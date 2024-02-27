#ifndef DATA_H
#define DATA_H

#include "User.h"
#include "Profile.h"

class Data
{
private:
    static vector<User> users;
    static User currentUser;
    static Profile currentProfile;

public:
    Data();
    static vector<User> getUsers();
    static void setUsers(vector<User> newUsers);
    static User getCurrentUser();
    static void setCurrentUser(User newCurrentUser);
    static Profile getCurrentProfile();
    static void setCurrentProfile(Profile newCurrentProfile);
    static void addUser(User newCurrentUser);
    static void deleteUser(string userId);
};

#endif // DATA_H
