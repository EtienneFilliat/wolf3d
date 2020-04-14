# Wolf3d over VNC
#
# VERSION               0.1
# TESTED ON:            Docker version 19.03.8-ce, build afacb8b7f0

FROM consol/ubuntu-xfce-vnc

USER 0
RUN apt-get -y update && \
    apt-get -y install gcc mono-mcs libcsfml-dev && \
    rm -rf /var/lib/apt/lists/*

COPY . /headless/Desktop/wolf3d
RUN chown -R 1000:1000 /headless/Desktop/wolf3d
USER 1000