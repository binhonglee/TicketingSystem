if [ $(uname) == "Darwin" ]; then
  brew install ant
  brew install jsoncpp
else
  sudo apt-get update
  sudo apt-get install libjsoncpp-dev
fi

cp lib/anttasks.jar ~
pushd ~
jar xf anttasks.jar
pushd -0
