## Instructions to Setup AWS EC2 Linux Instance

#### Run these commands from the terminal
```sh
# Connect to you instance
# NOTE: The AWS EC2 Linux machine's url may be different, check it by going to the AWS dashboard
#       Also provide the ssh key
#       Example of [user@]hostname: ec2-user@ec2-54-175-148-194.compute-1.amazonaws.com
$ ssh -i "~/.ssh/<your-AWS-key.pem>" [user@]hostname

$ sudo yum install python-setuptools
$ sudo yum install wget

# Let's download the installation file using wget:
$ wget --no-check-certificate https://pypi.python.org/packages/source/s/setuptools/setuptools-1.4.2.tar.gz

# Extract the files from the archive:
$ tar -xvf setuptools-1.4.2.tar.gz

# Enter the extracted directory:
$ cd setuptools-1.4.2

# Install setuptools using the Python we've installed (2.7.6)
$ sudo python2.7 setup.py install

# Let's download the setup files for pip and have Python (2.7) install it:
$ curl https://bootstrap.pypa.io/get-pip.py | sudo  python2.7 -

# Install django using pip
$ sudo pip install django
```

#### Add custom Security Group rule in AWS EC2 Instance
For example, it can/should be set to:  

- Type: `Custom TCP Rule`
- Protocol: `TCP`
- Port Range: `8000`
- Source: `0.0.0.0/0`

#### Send HTTP request to your AWS Linux Instance using curl
`curl --cacert ~/.ssh/<your-AWS-key.pem> -H 'Accept: application/json; indent=4' http://107.21.171.13:8000`

NOTE: The AWS EC2 Linux machine's url may be different, check it by going to the AWS dashboard Also provide the ssh key

#### Sources
- https://ashokfernandez.wordpress.com/2014/03/11/deploying-a-django-app-to-amazon-aws-with-nginx-gunicorn-git/
- http://stackoverflow.com/questions/9865621/connecting-to-ec2-django-development-server
