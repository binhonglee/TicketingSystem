# Ticketing System

## build.xml

| Command | Action |
|:-------------|:---------------------------|
| `ant build` | Build the project. |
| `ant test` | Run test (Currently only build and clean the project) |

## Person.hpp / Person.cpp

#### Constructors

| Parameters | Task |
|:-----------|:-----------------------------|
| `()` | Empty constructor. |
| `(string newName, string newEmail, string newPhoneNo, string newPassword, int newId)` | Constructor with all parameters to populate all data slots in the object. |

#### Functions

| Function | Task |
|:----------------------|:-------------------------|
| `void setName(string);` | Set `name` to the new given input. |
| `string getName();` | Return `name` to caller. |
| `void setEmail(string);` | Set `email` to the new given input. |
| `string getEmail();` | Return `email` to caller. |
| `void setPhoneNo(string);` | Set `phoneNo` to the new given input. |
| `string getPhoneNo();` | Return `phoneNo` to caller. |
| `void setPassword(string);` | Set `password` to the new given input. |
| `string getPassword();` | Return `password` to the caller. |
| `bool checkPassword(string);` | Return if the given string matches `password`. |
| `int getId();` | Return `id` to the caller. |

## LogInSystem.hpp / LogInSystem.cpp

#### Constructors

| Parameters | Task |
|:-----------|:-----------------------------------|
| `()` | Creates an empty `LogInSystem` with nothing in the `users` vector. |
| `(string filename)` | Initialize the `users` vector from the file of the given filename. |

#### Functions

| Function | Task |
|:----------------------|:-------------------------|
| `Person getUser(string);` | Takes in a string parameter that will be used to searched for a matching username in the users vector. |
| `Person getUser(int);` | Takes in an int parameter that will be used to searched for a matching id in the users vector. |
| `int login();` | Verify user credentials and return the user's id. |
| `void loggedIn(Person);` | Takes in a Person parameter after the user has logged in as that identity. It provides the user options to display and modify the information of that specific identity in the database (vector). |
| `Person registration();` | Request all the required information from the user to register for a new account and add them into the users vector. |
| `Person editCredentials(Person);` | Takes in a `Person` parameter and make edit to it according to the user's intention. It will then return the updated Person to the caller. |
| `void update(Person);` | Take in a `Person` parameter that is to be updated into the users vector. It will search for the `Person` in the vector with matching ID and replace it. |
| `string chgUsername();` | Changes the `username` of the `Person`. |
| `string chgPassword(Person);` | Changes the `password` of the `Person`. |
| `string chgEmail();` | Changes the `email` of the `Person`. |
| `string chgPhoneNo();` | Changes the `phoneNo` of the `Person`.

## Vehicle.hpp / Vehicle.cpp

#### Constructors

| Parameters | Task |
|:-----------|:-----------------------------|
| `(int length, int width, int id)` | Basic constructor that fill in the rest of the missing information with "TBA". |
| `(string type, int length, int width, string origin, string destination, string dateNtime, int id)` | Complete constructor with all the information except the seatMap. |
| `(string type, int length, int width, string origin, string destination, string dateNtime, int id, vector< vector<int> > seatMap)` | Complete constructor that is used to read data from the database. |

#### Functions

| Function | Task |
|:---------------------------|:-------------------------|
| `void setType(string type);` | Set `type` to the new given input. |
| `void setOrigin(string origin);` | Set `origin` to the new given input. |
| `void setDestination(string destination);` | Set `destination` to the new given input. |
| `void setDateNTime(string dateNtime);` | Set `dateNtime` to the new given input. |
| `string getType();` | Return `type` to the caller. |
| `int getLength();` | Return `length` to the caller. |
| `int getWidth();` | Return `width` to the caller. |
| `string getOrigin();` | Return `origin` to the caller. |
| `string getDestination();` | Return `destination` to the caller. |
| `string getDateNTime();` | Return `dateNtime` to the caller. |
| `int getId();` | Return `id` to the caller. |
| `void initialize();` | Initialize the `seatMap` to the intended size. |
| `bool bookSeat(int x, int y, int guestId);` | Register a specific seat to the given guestId. Returns if the proces is successful. |
| `bool checkAvailabilty(int x, int y);` | Check if the seat at the given coordinate is still available. |
| `void printMap();` | Print the map with label of 'A' as *available* and 'X' as *not available*. |
| `void printMap(int guestId);` | Takes in the user id and print the map with label of 'A' as *available*, 'U' as the *user* and 'X' as *not available*. |

## VehicleManager.hpp / VehicleManager.cpp

#### Constructors

| Parameters | Task |
|:-----------|:--------------------------------|
| `()` | Empty constructor. Creates an empty vector of `vehicles`. |
| `(string jsonFile)` | Creates a vector of `vehicles` by importing the data from a json file. |

#### Functions

| Function | Task |
|:----------------------------------|:-------------------------|
| `bool add(Vehicle newVehicle);` | Add a new `Vehicle` into the vector. |
| `bool remove(Vehicle toRemove);` | Remove a specific `Vehicle` from the vector. |
| `Vehicle get(int id);` | Get a specific `Vehicle` with the given `id`. |
| `void toJson(string jsonFile);` | Export all data to a json file. |
| `int getId();` | Returns a suggested `id` for the next item. |
