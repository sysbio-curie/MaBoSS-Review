This repository contains multiple jupyter notebooks used in the review on MaBoSS

### Run in Binder : [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/vincent-noel/MaBoSS-Review/main?labpath=review_notebooks/)

### Run locally with Docker and Docker-compose
```
git clone https://github.com/sysbio-curie/MaBoSS-Review
cd MaBoSS-Review
docker-compose up -d
```
	
And then open your browser to this url : http://localhost:8888/notebooks/review_notebooks/

### Run locally with Docker
```
git clone https://github.com/sysbio-curie/MaBoSS-Review
cd MaBoSS-Review
docker build -t maboss_review .
docker run -p 8888:8888 -d maboss_review
```	

And then open your browser to this url : http://localhost:8888/notebooks/review_notebooks/
