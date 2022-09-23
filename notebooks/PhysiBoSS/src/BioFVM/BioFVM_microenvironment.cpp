/*
#############################################################################
# If you use BioFVM in your project, please cite BioFVM and the version     #
# number, such as below:                                                    #
#                                                                           #
# We solved the diffusion equations using BioFVM (Version 1.1.5) [1]        #
#                                                                           #
# [1] A. Ghaffarizadeh, S.H. Friedman, and P. Macklin, BioFVM: an efficient #
#    parallelized diffusive transport solver for 3-D biological simulations,#
#    Bioinformatics 32(8): 1256-8, 2016. DOI: 10.1093/bioinformatics/btv730 #
#                                                                           #
#############################################################################
#                                                                           #
# BSD 3-Clause License (see https://opensource.org/licenses/BSD-3-Clause)   #
#                                                                           #
# Copyright (c) 2015-2016, Paul Macklin and the BioFVM Project              #
# All rights reserved.                                                      #
#                                                                           #
# Redistribution and use in source and binary forms, with or without        #
# modification, are permitted provided that the following conditions are    #
# met:                                                                      #
#                                                                           #
# 1. Redistributions of source code must retain the above copyright notice, #
# this list of conditions and the following disclaimer.                     #
#                                                                           #
# 2. Redistributions in binary form must reproduce the above copyright      #
# notice, this list of conditions and the following disclaimer in the       #
# documentation and/or other materials provided with the distribution.      #
#                                                                           #
# 3. Neither the name of the copyright holder nor the names of its          #
# contributors may be used to endorse or promote products derived from this #
# software without specific prior written permission.                       #
#                                                                           #
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS       #
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED #
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A           #
# PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER #
# OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  #
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,       #
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR        #
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    #
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING      #
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS        #
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.              #
#                                                                           #
#############################################################################
*/

#include "BioFVM_microenvironment.h"
#include "BioFVM_solvers.h"
#include "BioFVM_vector.h"
#include <cmath>

#include "BioFVM_basic_agent.h"

namespace BioFVM{

extern std::string BioFVM_version; 
extern std::string BioFVM_URL; 

Microenvironment* default_microenvironment = NULL; 

void set_default_microenvironment( Microenvironment* M )
{ default_microenvironment = M; }
Microenvironment* get_default_microenvironment( void )
{ return default_microenvironment; }

void zero_function( std::vector<double>& position, std::vector<double>& input , std::vector<double>* write_destination )
{
	for( int i=0 ; i < (int) write_destination->size() ; i++ )
	{ (*write_destination)[i] = 0.0; }
	return; 
}

void one_function( std::vector<double>& position, std::vector<double>& input , std::vector<double>* write_destination )
{
	for( int i=0 ; i < (int) write_destination->size() ; i++ )
	{ (*write_destination)[i] = 1.0; }
	return; 
}

void zero_function( Microenvironment* pMicroenvironment, int voxel_index, std::vector<double>* write_destination ) 
{
	for( int i=0 ; i < (int) write_destination->size() ; i++ )
	{ (*write_destination)[i] = 0.0; }
	return; 
}

void one_function( Microenvironment* pMicroenvironment, int voxel_index, std::vector<double>* write_destination )
{
	for( int i=0 ; i < (int) write_destination->size() ; i++ )
	{ (*write_destination)[i] = 1.0; }
	return; 
}

void empty_diffusion_solver( Microenvironment& S, double dt )
{
	static bool setup_done = false; 
	if( !setup_done )
	{
		std::cout << "Using the empty diffusion solver ... " << std::endl; 
		setup_done = true; 
	}

	return; 
}

/* For a given field, return its number in the densities vector if present, else return -1 */
int Microenvironment::get_index(std::string density)
{
	auto it = indexes.find( density );
	if ( it != indexes.end() )
		return it->second;
	return -1;
}

Microenvironment::Microenvironment()
{	
	name = "unnamed"; 
	spatial_units = "none"; 
	time_units = "none";
	
	bulk_source_sink_solver_setup_done = false; 
	thomas_setup_done = false; 
	diffusion_solver_setup_done = false; 

	diffusion_decay_solver = empty_diffusion_solver;
	diffusion_decay_solver = diffusion_decay_solver__constant_coefficients_LOD_3D; 

	indexes.clear();

	mesh.resize(1,1,1); 
	one.resize( 1 , 1.0 ); 
	zero.resize( 1 , 0.0 );
	
	temporary_density_vectors1.resize( mesh.voxels.size() , zero ); 
	temporary_density_vectors2.resize( mesh.voxels.size() , zero ); 
	p_density_vectors = &temporary_density_vectors1;

	gradient_vectors.resize( mesh.voxels.size() ); 
	for( int k=0 ; k < (int) mesh.voxels.size() ; k++ )
	{
		gradient_vectors[k].resize( 1 ); 
		(gradient_vectors[k])[0].resize( 3, 0.0 );
	}
	gradient_vector_computed.resize( mesh.voxels.size() , false ); 

	bulk_supply_rate_function = zero_function; 
	bulk_supply_target_densities_function = zero_function; 
	bulk_uptake_rate_function = zero_function; 

	density_names.assign( 1 , "unnamed" ); 
	density_units.assign( 1 , "none" ); 

	diffusion_coefficients.assign( number_of_densities() , 0.0 ); 
	decay_rates.assign( number_of_densities() , 0.0 ); 
	
	one_half = one; 
	one_half *= 0.5; 
	
	one_third = one; 
	one_third /= 3.0;

	dirichlet_indices.clear();
	dirichlet_value_vectors.clear();	
	
	if(default_microenvironment==NULL)
		default_microenvironment=this;
	
	toWrite.clear();
}

Microenvironment::Microenvironment(std::string name)
{	
	Microenvironment();
	this->name=name;
}
void Microenvironment::add_dirichlet_node( int voxel_index, std::vector<double>& value )
{
	mesh.voxels[voxel_index].is_Dirichlet=true;
	dirichlet_indices.push_back( voxel_index );
	dirichlet_value_vectors.push_back( value ); 
}

void Microenvironment::update_dirichlet_node( int voxel_index , std::vector<double>& new_value )
{
	int n = 0; 
	while( dirichlet_indices[n] != voxel_index && n < (int) dirichlet_indices.size() )
	{ n++; }
		
	if( n == (int) dirichlet_indices.size() )
	{ 
		std::cout << "BioFVM Warning: No Dirichlet condition previously specified at voxel " << voxel_index << "! Creating a new one now ... " << std::endl; 
		add_dirichlet_node( voxel_index , new_value ); 
		return; 
	}
	dirichlet_value_vectors[n] = new_value; 
}

void Microenvironment::remove_dirichlet_node( int voxel_index )
{
	int n = 0; 
	mesh.voxels[voxel_index].is_Dirichlet=false;
	while( dirichlet_indices[n] != voxel_index && n < (int) dirichlet_indices.size() )
	{  n++; }
	
	if( n == (int) dirichlet_indices.size() )
	{ 
		std::cout << "BioFVM Warning: No Dirichlet condition previously specified at voxel " << voxel_index << "! Nothing to remove!" << std::endl; 
		return; 
	}
	
	// swap with the final node and then remove it 	
	dirichlet_indices[n] = dirichlet_indices[ dirichlet_indices.size()-1 ]; 
	dirichlet_value_vectors[n] = dirichlet_value_vectors[ dirichlet_value_vectors.size()-1 ]; 
	dirichlet_indices.pop_back();
	dirichlet_value_vectors.pop_back();
	
	return; 
}


void Microenvironment::apply_dirichlet_conditions( void )
{
	#pragma omp parallel for 
	for( int i=0 ; i < (int) dirichlet_indices.size() ; i++ )
	{ density_vector( dirichlet_indices[i] ) = dirichlet_value_vectors[i]; } 
}

void Microenvironment::resize_voxels( int new_number_of_voxes )
{
	if( mesh.Cartesian_mesh == true )
	{
		std::cout << "Error: only use Microenvironment::" << __FUNCTION__ << " as a fall-back for non-Cartesian meshes." << std::endl
				  << "\tUse one of the Microenvironment::resize_space() functions instead. Ignoring directive." << std::endl; 
		return; 
	}
	
	mesh.voxels.resize( new_number_of_voxes ); 
	
	temporary_density_vectors1.resize( mesh.voxels.size() , zero ); 
	temporary_density_vectors2.resize( mesh.voxels.size() , zero ); 
		
	gradient_vectors.resize( mesh.voxels.size() ); 
	for( int k=0 ; k < (int) mesh.voxels.size() ; k++ )
	{
		gradient_vectors[k].resize( number_of_densities() ); 
		for( int i=0 ; i < number_of_densities() ; i++ )
		{
			(gradient_vectors[k])[i].resize( 3, 0.0 );
		}
	}
	gradient_vector_computed.resize( mesh.voxels.size() , false ); 	
}


void Microenvironment::resize_space( int x_nodes, int y_nodes, int z_nodes )
{
	mesh.resize( x_nodes, y_nodes , z_nodes ); 

	temporary_density_vectors1.assign( mesh.voxels.size() , zero ); 
	temporary_density_vectors2.assign( mesh.voxels.size() , zero ); 
		
	gradient_vectors.resize( mesh.voxels.size() ); 
	for( int k=0 ; k < (int) mesh.voxels.size() ; k++ )
	{
		gradient_vectors[k].resize( number_of_densities() ); 
		for( int i=0 ; i < number_of_densities() ; i++ )
		{
			(gradient_vectors[k])[i].resize( 3, 0.0 );
		}
	}
	gradient_vector_computed.resize( mesh.voxels.size() , false ); 	
	return;  
}

void Microenvironment::resize_space( double x_start, double x_end, double y_start, double y_end, double z_start, double z_end , int x_nodes, int y_nodes, int z_nodes )
{
	mesh.resize( x_start, x_end, y_start, y_end, z_start, z_end, x_nodes, y_nodes , z_nodes  ); 

	temporary_density_vectors1.assign( mesh.voxels.size() , zero ); 
	temporary_density_vectors2.assign( mesh.voxels.size() , zero ); 
	
	gradient_vectors.resize( mesh.voxels.size() ); 
	for( int k=0 ; k < (int) mesh.voxels.size() ; k++ )
	{
		gradient_vectors[k].resize( number_of_densities() ); 
		for( int i=0 ; i < number_of_densities() ; i++ )
		{
			(gradient_vectors[k])[i].resize( 3, 0.0 );
		}
	}
	gradient_vector_computed.resize( mesh.voxels.size() , false ); 	
	
	return;  
}

void Microenvironment::resize_space( double x_start, double x_end, double y_start, double y_end, double z_start, double z_end , double dx_new , double dy_new , double dz_new )
{
	mesh.resize( x_start, x_end, y_start, y_end, z_start, z_end,  dx_new , dy_new , dz_new ); 

	temporary_density_vectors1.assign( mesh.voxels.size() , zero ); 
	temporary_density_vectors2.assign( mesh.voxels.size() , zero ); 
	
	gradient_vectors.resize( mesh.voxels.size() ); 
	for( int k=0 ; k < (int) mesh.voxels.size() ; k++ )
	{
		gradient_vectors[k].resize( number_of_densities() ); 
		for( int i=0 ; i < number_of_densities() ; i++ )
		{
			(gradient_vectors[k])[i].resize( 3, 0.0 );
		}
	}
	gradient_vector_computed.resize( mesh.voxels.size() , false ); 	
	return;  
}

void Microenvironment::resize_space_uniform( double x_start, double x_end, double y_start, double y_end, double z_start, double z_end , double dx_new )
{
 return resize_space( x_start, x_end, y_start, y_end, z_start, z_end , dx_new , dx_new, dx_new ); 
}

void Microenvironment::resize_densities( int new_size )
{
	zero.assign( new_size, 0.0 ); 
	one.assign( new_size , 1.0 );

	temporary_density_vectors1.assign( mesh.voxels.size() , zero );
	temporary_density_vectors2.assign( mesh.voxels.size() , zero );

	for( int k=0 ; k < (int) mesh.voxels.size() ; k++ )
	{
		gradient_vectors[k].resize( number_of_densities() ); 
		for( int i=0 ; i < number_of_densities() ; i++ )
		{
			(gradient_vectors[k])[i].resize( 3, 0.0 );
		}
	}
	gradient_vector_computed.resize( mesh.voxels.size() , false ); 	
	
	diffusion_coefficients.assign( new_size , 0.0 ); 
	decay_rates.assign( new_size , 0.0 ); 

	density_names.assign( new_size, "unnamed" ); 
	density_units.assign( new_size , "none" ); 

	one_half = one; 
	one_half *= 0.5; 
	
	one_third = one; 
	one_third /= 3.0; 
	
	return; 
}

void Microenvironment::add_density( void )
{
	// update 1, 0 
	zero.push_back( 0.0 ); 
	one.push_back( 1.0 );
	
	// update units
	density_names.push_back( "unnamed" ); 
	density_units.push_back( "none" ); 

	// update coefficients 
	diffusion_coefficients.push_back( 0.0 ); 
	decay_rates.push_back( 0.0 ); 
	
	// update sources and such 
	for( int i=0; i < (int) temporary_density_vectors1.size() ; i++ )
	{
		temporary_density_vectors1[i].push_back( 0.0 ); 
		temporary_density_vectors2[i].push_back( 0.0 ); 
	}

	// resize the gradient data structures 
	for( int k=0 ; k < (int) mesh.voxels.size() ; k++ )
	{
		gradient_vectors[k].resize( number_of_densities() ); 
		for( int i=0 ; i < number_of_densities() ; i++ )
		{
			(gradient_vectors[k])[i].resize( 3, 0.0 );
		}
	}

	gradient_vector_computed.resize( mesh.voxels.size() , false ); 	
	
	one_half = one; 
	one_half *= 0.5; 
	
	one_third = one; 
	one_third /= 3.0; 
}

void Microenvironment::add_density( std::string name , std::string units )
{
	// update 1, 0 
	zero.push_back( 0.0 ); 
	one.push_back( 1.0 );

	// update units
	density_names.push_back( name ); 
	density_units.push_back( units );
	// Add density index 
	indexes[name] = density_names.size()-1;

	// update coefficients 
	diffusion_coefficients.push_back( 0.0 ); 
	decay_rates.push_back( 0.0 ); 
	
	// update sources and such 
	for( int i=0; i < (int) temporary_density_vectors1.size() ; i++ )
	{
		temporary_density_vectors1[i].push_back( 0.0 ); 
		temporary_density_vectors2[i].push_back( 0.0 ); 
	}

	// resize the gradient data structures, 
	for( int k=0 ; k < (int) mesh.voxels.size() ; k++ )
	{
		gradient_vectors[k].resize( number_of_densities() ); 
		for( int i=0 ; i < number_of_densities() ; i++ )
		{
			(gradient_vectors[k])[i].resize( 3, 0.0 );
		}
	}
	gradient_vector_computed.resize( mesh.voxels.size() , false ); 	

	one_half = one; 
	one_half *= 0.5; 
	
	one_third = one; 
	one_third /= 3.0; 
}

void Microenvironment::add_density( std::string name , std::string units, double diffusion_constant, double decay_rate )
{
	// update 1, 0 
	zero.push_back( 0.0 ); 
	one.push_back( 1.0 );
	
	// update units
	density_names.push_back( name ); 
	density_units.push_back( units ); 
	// Add density index 
	indexes[name] = density_names.size()-1;

	// update coefficients 
	diffusion_coefficients.push_back( diffusion_constant ); 
	decay_rates.push_back( decay_rate ); 
	
	// update sources and such 
	for( int i=0; i < (int) temporary_density_vectors1.size() ; i++ )
	{
		temporary_density_vectors1[i].push_back( 0.0 ); 
		temporary_density_vectors2[i].push_back( 0.0 ); 
	}

	// resize the gradient data structures 
	for( int k=0 ; k < (int) mesh.voxels.size() ; k++ )
	{
		gradient_vectors[k].resize( number_of_densities() ); 
		for( int i=0 ; i < number_of_densities() ; i++ )
		{
			(gradient_vectors[k])[i].resize( 3, 0.0 );
		}
	}
	gradient_vector_computed.resize( mesh.voxels.size() , false ); 	

	one_half = one; 
	one_half *= 0.5; 
	
	one_third = one; 
	one_third /= 3.0; 
}

void Microenvironment::set_density( int index , std::string name , std::string units )
{
	density_names[index] = name; 
	// Add density index 
	indexes[name] = density_names.size()-1;
	density_units[index] = units; 
	return; 
}

void Microenvironment::set_density( int index , std::string name , std::string units , double diffusion_constant , double decay_rate )
{
	density_names[index] = name; 
	// Add density index 
	indexes[name] = density_names.size()-1;
	density_units[index] = units; 
	
	diffusion_coefficients[index] = diffusion_constant; 
	decay_rates[index] = decay_rate;	
	return; 
}

int Microenvironment::voxel_index( int i, int j, int k )
{ return mesh.voxel_index(i,j,k) ; }

std::vector<int> Microenvironment::cartesian_indices( int n )
{ return mesh.cartesian_indices( n ); }

int Microenvironment::nearest_voxel_index( std::vector<double>& position )
{ return mesh.nearest_voxel_index( position ); }
int Microenvironment::nearest_voxel_index( Vector3d& position )
{ return mesh.nearest_voxel_index( position ); }

Voxel& Microenvironment::voxels( int voxel_index )
{ return mesh.voxels[voxel_index]; }

std::vector<int> Microenvironment::nearest_cartesian_indices( std::vector<double>& position )
{ return mesh.nearest_cartesian_indices( position ); }
 
Voxel& Microenvironment::nearest_voxel( std::vector<double>& position )
{ return mesh.nearest_voxel( position ); }

std::vector<double>& Microenvironment::nearest_density_vector( std::vector<double>& position )
{ return (*p_density_vectors)[ mesh.nearest_voxel_index( position ) ]; }

std::vector<double>& Microenvironment::nearest_density_vector( int voxel_index )
{ return (*p_density_vectors)[ voxel_index ]; }

std::vector<double>& Microenvironment::operator()( int i, int j, int k )
{ return (*p_density_vectors)[ voxel_index(i,j,k) ]; }

std::vector<double>& Microenvironment::operator()( int i, int j )
{ return (*p_density_vectors)[ voxel_index(i,j,0) ]; }

std::vector<double>& Microenvironment::operator()( int n )
{ return (*p_density_vectors)[ n ]; }

std::vector<double>& Microenvironment::density_vector( int i, int j, int k )
{ return (*p_density_vectors)[ voxel_index(i,j,k) ]; }

std::vector<double>& Microenvironment::density_vector( int i, int j )
{ return (*p_density_vectors)[ voxel_index(i,j,0) ]; }

std::vector<double>& Microenvironment::density_vector( int n )
{ return (*p_density_vectors)[ n ]; }

void Microenvironment::simulate_diffusion_decay( double dt )
{
	if( diffusion_decay_solver )
	{ diffusion_decay_solver( *this, dt ); }
	else
	{
		std::cout << "Warning: diffusion-reaction-source/sink solver not set for Microenvironment object at " << this << ". Nothing happened!" << std::endl; 
		std::cout << "   Consider using Microenvironment::auto_choose_diffusion_decay_solver(void) ... " << std::endl 
		<< std::endl; 
	}
	return; 
}

void Microenvironment::auto_choose_diffusion_decay_solver( void )
{
	// set the safest choice 
	diffusion_decay_solver = diffusion_decay_solver__constant_coefficients_explicit; 

	std::cout << "Warning: auto-selection of diffusion-decay-source/sink solver not fully implemented!" << std::endl;

 // eventual logic: if non-Cartesian, use explicit
 // if Cartesian, if non-variable, use the constant coefficient super-fast code
 // otherwise, use the variable coefficient code 

}
 
void Microenvironment::display_information( std::ostream& os )
{
	os << std::endl << "Microenvironment summary: " << name << ": " << std::endl; 
	mesh.display_information( os ); 
	os << "Densities: (" << number_of_densities() << " total)" << std::endl; 
	for( int i = 0 ; i < (int) density_names.size() ; i++ )
	{
		os << "   " << density_names[i] << ":" << std::endl;
		os << "     units: " << density_units[i] << std::endl; 
		os << "     diffusion coefficient: " << diffusion_coefficients[i];
		os << " " << spatial_units << "^2 / " << time_units << std::endl;
		os << "     decay rate: " << decay_rates[i];
		os << " " << time_units << "^-1" << std::endl; 
		os << "     diffusion length scale: " << sqrt( diffusion_coefficients[i] / ( 1e-12 + decay_rates[i] ) ) << " "; 
		os << spatial_units << std::endl << std::endl; 
	}
	os << std::endl; 
	return; 
}

/* Generate list of voxels indexes to write for a given ratio (random) 
   ratio: proportion of voxels values to write: from 1 all to 0 none*/
void Microenvironment::list_indexes( double ratio )
{
	toWrite.clear();
	for ( int i = 0; i < number_of_voxels(); i++ )
	{
		if ( UniformRandom() <= ratio )
			toWrite.push_back(i);
	}
}

/* Write microenvironment given density values of the voxels in the toWrite list */
void Microenvironment::write_density( std::ostream& os, int dens )
{
	for ( int i : toWrite )
	{
		double fill = nearest_density_vector(i)[dens];
		if ( fill > small_value )
		{
			os << voxel_center(i)[0] << ";";
			os << voxel_center(i)[1] << ";";
			os << voxel_center(i)[2] << ";";
			os << nearest_density_vector(i)[dens] << std::endl;
		}
	}
}

/* Return microenvironment given density total value */
double Microenvironment::total_density( int dens )
{
	double res = 0;
	for ( int i = 0; i < number_of_voxels(); i++ )
	{
			res += nearest_density_vector(i)[dens];
	}
	return res;
}

int Microenvironment::number_of_densities( void )
{ return (*p_density_vectors)[0].size(); }

int Microenvironment::number_of_voxels( void )
{ return mesh.voxels.size(); }

int Microenvironment::number_of_voxel_faces( void )
{ return mesh.voxel_faces.size(); } 

void Microenvironment::write_to_matlab( std::string filename )
{
	int number_of_data_entries = mesh.voxels.size();
	int size_of_each_datum = 3 + 1 + (*p_density_vectors)[0].size(); 

	FILE* fp = write_matlab_header( size_of_each_datum, number_of_data_entries,  filename, "multiscale_microenvironment" );  

	// storing data as cols 
	for( int i=0; i < number_of_data_entries ; i++ )
	{
		fwrite( (char*) &( mesh.voxels[i].center[0] ) , sizeof(double) , 1 , fp ); 
		fwrite( (char*) &( mesh.voxels[i].center[1] ) , sizeof(double) , 1 , fp );   
		fwrite( (char*) &( mesh.voxels[i].center[2] ) , sizeof(double) , 1 , fp ); 
		fwrite( (char*) &( mesh.voxels[i].volume ) , sizeof(double) , 1 , fp ); 

		// densities  

		for( int j=0 ; j < (int) (*p_density_vectors)[i].size() ; j++)
		{ fwrite( (char*) &( ((*p_density_vectors)[i])[j] ) , sizeof(double) , 1 , fp ); }
	}

	fclose( fp ); 
	return;
}


void Microenvironment::simulate_bulk_sources_and_sinks( double dt )
{
	if( !bulk_source_sink_solver_setup_done )
	{
		bulk_source_sink_solver_temp1.resize( mesh.voxels.size() , zero );
		bulk_source_sink_solver_temp2.resize( mesh.voxels.size() , zero );
		bulk_source_sink_solver_temp3.resize( mesh.voxels.size() , zero );
		
		bulk_source_sink_solver_setup_done = true; 
	}
	
	#pragma omp parallel for
	for( int i=0; i < (int) mesh.voxels.size() ; i++ )
	{
		bulk_supply_rate_function( this,i, &bulk_source_sink_solver_temp1[i] ); // temp1 = S
		bulk_supply_target_densities_function( this,i, &bulk_source_sink_solver_temp2[i]); // temp2 = T
		bulk_uptake_rate_function( this,i, &bulk_source_sink_solver_temp3[i] ); // temp3 = U

		
		bulk_source_sink_solver_temp2[i] *= bulk_source_sink_solver_temp1[i]; // temp2 = S*T
		axpy( &(*p_density_vectors)[i] , dt , bulk_source_sink_solver_temp2[i] ); // out = out + dt*temp2 = out + dt*S*T
		bulk_source_sink_solver_temp3[i] += bulk_source_sink_solver_temp1[i]; // temp3 = U+S
		bulk_source_sink_solver_temp3[i] *= dt; // temp3 = dt*(U+S)
		bulk_source_sink_solver_temp3[i] += one; // temp3 = 1 + dt*(U+S)
		
		(*p_density_vectors)[i] /= bulk_source_sink_solver_temp3[i];
	}
	
	return; 
}

/**void Microenvironment::simulate_cell_sources_and_sinks( std::vector<Basic_Agent*>& basic_agent_list , double dt )
{
	#pragma omp parallel for
	for( int i=0 ; i < basic_agent_list.size() ; i++ )
	{		
		basic_agent_list[i]->simulate_secretion_and_uptake( this , dt ); 
	}
	
	return; 
}*/

/**void Microenvironment::simulate_cell_sources_and_sinks( double dt )
{
	agent_container->simulate_cell_sources_and_sinks(this, dt);
}*/

void Microenvironment::update_rates( void )
{
	if( (int) supply_target_densities_times_supply_rates.size() != number_of_voxels() )
	{ supply_target_densities_times_supply_rates.assign( number_of_voxels() , zero ); }

	if( (int) supply_rates.size() != number_of_voxels() )
	{ supply_rates.assign( number_of_voxels() , zero ); }
	
	if( (int) uptake_rates.size() != number_of_voxels() )
	{ uptake_rates.assign( number_of_voxels() , zero ); }

	#pragma omp parallel for 
	for( int i=0 ; i < number_of_voxels() ; i++ )
	{
		bulk_uptake_rate_function( this,i, &(uptake_rates[i]) ); 		
		bulk_supply_rate_function( this,i, &(supply_rates[i]) ); 		
		bulk_supply_target_densities_function( this,i, &(supply_target_densities_times_supply_rates[i]) );
		
		supply_target_densities_times_supply_rates[i] *= supply_rates[i]; 
	}
	return; 
}

std::vector<gradient>& Microenvironment::gradient_vector(int i, int j, int k)
{
	int n = voxel_index(i,j,k);
	if( gradient_vector_computed[n] == false )
	{
		compute_gradient_vector( n );
	}
	
	return gradient_vectors[n];
}

std::vector<gradient>& Microenvironment::gradient_vector(int i, int j )
{
	int n = voxel_index(i,j,0);
	if( gradient_vector_computed[n] == false )
	{
		compute_gradient_vector( n );
	}
	
	return gradient_vectors[n];
}

std::vector<gradient>& Microenvironment::gradient_vector(int n )
{
	// if the gradient has not yet been computed, then do it!
	if( gradient_vector_computed[n] == false )
	{
		compute_gradient_vector( n );
	}
	
	return gradient_vectors[n];
}
	
std::vector<gradient>& Microenvironment::nearest_gradient_vector( std::vector<double>& position )
{
	int n = nearest_voxel_index( position );
	if( gradient_vector_computed[n] == false )
	{
		compute_gradient_vector( n );
	}
	
	return gradient_vectors[n];
}

void Microenvironment::compute_all_gradient_vectors( void )
{
	static double two_dx = mesh.dx; 
	static double two_dy = mesh.dy; 
	static double two_dz = mesh.dz; 
	static bool gradient_constants_defined = false; 
	if( gradient_constants_defined == false )
	{
		two_dx *= 2.0; 
		two_dy *= 2.0; 
		two_dz *= 2.0;
		gradient_constants_defined = true; 
	}
	
	#pragma omp parallel for 
	for( int k=0; k < (int) mesh.z_coordinates.size() ; k++ )
	{
		for( int j=0; j < (int) mesh.y_coordinates.size() ; j++ )
		{
			
			for( int i=1; i < (int) mesh.x_coordinates.size()-1 ; i++ )
			{
				for( int q=0; q < number_of_densities() ; q++ )
				{
					int n = voxel_index(i,j,k);
					// x-derivative of qth substrate at voxel n
					gradient_vectors[n][q][0] = (*p_density_vectors)[n+thomas_i_jump][q]; 
					gradient_vectors[n][q][0] -= (*p_density_vectors)[n-thomas_i_jump][q]; 
					gradient_vectors[n][q][0] /= two_dx; 
					
					gradient_vector_computed[n] = true; 
 				}
			}
			
		}
	}
	
	#pragma omp parallel for 
	for( int k=0; k < (int) mesh.z_coordinates.size() ; k++ )
	{
		for( int i=0; i < (int) mesh.x_coordinates.size() ; i++ )
		{
			
			for( int j=1; j < (int) mesh.y_coordinates.size()-1 ; j++ )
			{
				for( int q=0; q < number_of_densities() ; q++ )
				{
					int n = voxel_index(i,j,k);
					// y-derivative of qth substrate at voxel n
					gradient_vectors[n][q][1] = (*p_density_vectors)[n+thomas_j_jump][q]; 
					gradient_vectors[n][q][1] -= (*p_density_vectors)[n-thomas_j_jump][q]; 
					gradient_vectors[n][q][1] /= two_dy; 
					gradient_vector_computed[n] = true; 
				}
			}
			
		}
	}

	#pragma omp parallel for 
	for( int j=0; j < (int) mesh.y_coordinates.size() ; j++ )
	{
		for( int i=0; i < (int) mesh.x_coordinates.size() ; i++ )
		{
			
			for( int k=1; k < (int) mesh.z_coordinates.size()-1 ; k++ )
			{
				for( int q=0; q < number_of_densities() ; q++ )
				{
					int n = voxel_index(i,j,k);
					// y-derivative of qth substrate at voxel n
					gradient_vectors[n][q][2] = (*p_density_vectors)[n+thomas_k_jump][q]; 
					gradient_vectors[n][q][2] -= (*p_density_vectors)[n-thomas_k_jump][q]; 
					gradient_vectors[n][q][2] /= two_dz; 
					gradient_vector_computed[n] = true; 
				}
			}
			
		}
	}

	return; 
}

void Microenvironment::compute_gradient_vector( int n )
{
	static double two_dx = mesh.dx; 
	static double two_dy = mesh.dy; 
	static double two_dz = mesh.dz; 
	static bool gradient_constants_defined = false; 
	static std::vector<int> indices(3,0);
	
	if( gradient_constants_defined == false )
	{
		two_dx *= 2.0; 
		two_dy *= 2.0; 
		two_dz *= 2.0;
		gradient_constants_defined = true; 
	}	
	
	indices = cartesian_indices( n );
	
	// d/dx 
	if( indices[0] > 0 && indices[0] < (int) mesh.x_coordinates.size()-1 )
	{
		for( int q=0; q < number_of_densities() ; q++ )
		{
			gradient_vectors[n][q][0] = (*p_density_vectors)[n+thomas_i_jump][q]; 
			gradient_vectors[n][q][0] -= (*p_density_vectors)[n-thomas_i_jump][q]; 
			gradient_vectors[n][q][0] /= two_dx; 
			gradient_vector_computed[n] = true; 
		}
	}
	
	// d/dy 
	if( indices[1] > 0 && indices[1] < (int) mesh.y_coordinates.size()-1 )
	{
		for( int q=0; q < number_of_densities() ; q++ )
		{
			gradient_vectors[n][q][1] = (*p_density_vectors)[n+thomas_j_jump][q]; 
			gradient_vectors[n][q][1] -= (*p_density_vectors)[n-thomas_j_jump][q]; 
			gradient_vectors[n][q][1] /= two_dy; 
			gradient_vector_computed[n] = true; 
		}
	}
	
	// d/dz 
	if( indices[2] > 0 && indices[2] < (int) mesh.z_coordinates.size()-1 )
	{
		for( int q=0; q < number_of_densities() ; q++ )
		{
			gradient_vectors[n][q][2] = (*p_density_vectors)[n+thomas_k_jump][q]; 
			gradient_vectors[n][q][2] -= (*p_density_vectors)[n-thomas_k_jump][q]; 
			gradient_vectors[n][q][2] /= two_dz; 
			gradient_vector_computed[n] = true; 
		}
	}
	
	return; 
}

void Microenvironment::reset_all_gradient_vectors( void )
{
	for( int k=0 ; k < (int) mesh.voxels.size() ; k++ )
	{
		for( int i=0 ; i < number_of_densities() ; i++ )
		{
			(gradient_vectors[k])[i].resize( 3, 0.0 );
		}
	}
	gradient_vector_computed.assign( mesh.voxels.size() , false ); 	
}

};
