FROM debian:stretch
RUN apt update
RUN apt install -y build-essential cmake curl git openjdk-8-jre python scons

RUN git clone https://github.com/emscripten-core/emsdk.git /emsdk

#RUN cd /emsdk && git pull
RUN cd /emsdk && ./emsdk install sdk-1.39.3-64bit
RUN cd /emsdk && ./emsdk activate sdk-1.39.3-64bit
#RUN ln -sf /bin/bash /bin/sh
RUN /bin/bash -c "cd /emsdk && source ./emsdk_env.sh"
RUN echo 'source /emsdk/emsdk_env.sh' >> /etc/bash.bashrc
RUN mkdir /build
WORKDIR /build
