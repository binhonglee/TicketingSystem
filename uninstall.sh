if [ $kernel == "Darwin" ]; then
  sudo apt-get remove --purge libjsoncpp-dev
else
  brew uninstall jsoncpp
fi

cd ../
echo "Deleting project files"
rm -rf TicketingSystem
echo "Removing additional installed library"
rm -rf ~/anttasks.jar
