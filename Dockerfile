FROM ubuntu:22.04 AS base

# Set timezone. It's required by lots of packages. 
# It's also better than setting DEBIAN_FRINTEND=noninteractive since, in dev-environment
# somtimes interactive tools are needed.
ENV TZ=Europe/Warsaw
RUN ln -snf /usr/share/zoneinfo/"$TZ" /etc/localtime && echo "$TZ" > /etc/timezone

# Install packages
RUN apt-get update && apt-get install -y \
    clang \
    clang-format \
    clang-tidy \
    clang-tools \
    cmake \
    cppcheck \
    doxygen \
    g++ \
    gcc \
    gdb \
    git \
    googletest \
    graphviz \
    make \
    python3 \
    python3-pip \
    wget \
    && apt-get clean

# Istall Gcovr gcov data presentation tool
# https://github.com/gcovr/gcovr
RUN pip3 install gcovr

# Set shell variable
ENV SHELL=/usr/bin/bash

# Default values for the user and group
ARG USER_ID
ARG USER_NAME=user
ARG GROUP_ID
ARG GROUP_NAME=user

# Configure local user
ARG uid
ARG username
RUN useradd -G www-data,root -u ${uid} -d /home/${username} ${username}
RUN mkdir -p /home/${username}/.composer && \
    chown -R ${username}:${username} /home/${username}
USER ${username}

# Set current path to the project folder
ENV USER_APP_PATH=/home/${username}/project
WORKDIR ${USER_APP_PATH}%  
