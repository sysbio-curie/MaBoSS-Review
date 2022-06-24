FROM colomoto/colomoto-docker:2022-05-01
MAINTAINER Vincent Noel <contact@vincent-noel.fr>

USER root
RUN apt-get update && apt-get install -y git
RUN /opt/conda/bin/pip install jupyterlab jupyter-offlinenotebook jupyterlab-link-share git+https://github.com/colomoto/pyMaBoSS git+https://github.com/bioasp/bonesis.git mpbn --upgrade

ADD notebooks/ review_notebooks
RUN chown -R user:user review_notebooks

USER user
