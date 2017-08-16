if [ $kernel == "Darwin" ]; then
  brew install jsoncpp
else
  sudo apt-get update
  sudo apt-get install libjsoncpp-dev
fi

cp lib/anttasks.jar ~
pushd ~
jar xf anttasks.jar
pushd -0
