FROM debian:testing-slim

RUN apt-get update -y \
  && apt-get install -y -o Acquire::Retries=10 --no-install-recommends \
    texlive-full \
    fontconfig \
    fonts-noto-cjk \
    ruby-dev \
    g++ \
    make \
    curl \
    qqwing \
		git \
  && apt-get clean \
  && curl -LO https://github.com/jgm/pandoc/releases/download/2.8/pandoc-2.8-1-amd64.deb \
  && dpkg -i pandoc-2.8-1-amd64.deb \
  && rm pandoc-2.8-1-amd64.deb
RUN gem install bundler

COPY Gemfile /Gemfile
COPY Gemfile.lock /Gemfile.lock
RUN bundle install
RUN rm /Gemfile /Gemfile.lock
