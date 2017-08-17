if [ $(uname) == "Darwin" ]; then
  brew uninstall jsoncpp
  brew uninstall ant
else
  sudo apt-get remove --purge libjsoncpp-dev
fi

cd ../
echo "Deleting project files"
rm -rf TicketingSystem
echo "Removing additional installed library"
rm -rf ~/anttasks.jar
