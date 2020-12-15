# Container image that runs your code
FROM archlinux:base-devel-20201206.0.10501

# Copies your code file from your action repository to the filesystem path `/` of the container
COPY Makefile /Makefile
COPY src/ /src/

RUN pacman -Syu --noconfirm libevdev
RUN export CPATH=/usr/include/libevdev-1.0 && make
