# Docker

### Image

An image is a lightweight, stand-alone, executable package that includes everything needed to run a piece of software, including the code, a runtime, libraries, environment variables, and config files.

### Container

A container is a runtime instance of an image — what the image becomes in memory when actually executed. It runs completely isolated from the host environment by default, only accessing host files and ports if configured to do so.

- Containers run apps natively on the host machine's kernel.
- They have better performance characteristics than virtual machines that only get virtual access to host resources through a hypervisor.
- Containers can get native access, each one running in a discrete process, taking no more memory than any other executable.

### Dockerfile

A Dockerfile defines what goes on in the environment inside your container. Access to resources like networking interfaces and disk drives is virtualized inside this environment, which is isolated from the rest of your system, so you have to map ports to the outside world, and be specific about what files you want to "copy in" to that environment. However, after doing that, you can expect that the build of your app defined in this Dockerfile will behave exactly the same wherever it runs.

### Scaling and Load-Balancing

**Services** are really just "containers in production." A service only runs one image, but it codifies the way that image runs - what ports it should use, how many replicas of the container should run so the service has the capacity it needs, and so on. Scaling a service changes the number of container instances running that piece of software, assigning more computing resources to the service in the process.

To define, run, and scale services with the Docker platform - just write a `docker-compose.yml` file.

A `docker-compose.yml` file is a YAML file that defines how Docker containers should behave in production.

### Commands

```bash
# Build an image from a docker file; -t flag gives human friendly name to the image
$ docker build -t friendlyhello .

# Manage images
$ docker images

# Manage containers
$ docker container
```


