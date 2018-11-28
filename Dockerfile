FROM debian:stretch
RUN apt update
RUN apt install -y build-essential cmake curl git openjdk-8-jre python scons

RUN curl https://s3.amazonaws.com/mozilla-games/emscripten/releases/emsdk-portable.tar.gz | tar -xvzf -

RUN cd /emsdk-portable && ./emsdk update
RUN cd /emsdk-portable && ./emsdk install sdk-1.38.20-64bit
RUN cd /emsdk-portable && ./emsdk activate sdk-1.38.20-64bit
#RUN ln -sf /bin/bash /bin/sh
RUN /bin/bash -c "cd /emsdk-portable && source ./emsdk_env.sh"
RUN echo 'source /emsdk-portable/emsdk_env.sh' >> /etc/bash.bashrc
RUN mkdir /build
WORKDIR /build
