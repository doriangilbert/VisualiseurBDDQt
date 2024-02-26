#include "Data.h"

vector<User> Data::users;
User Data::currentUser;
Profile Data::currentProfile;

vector<User> Data::getUsers()
{
    return users;
}

void Data::setUsers(vector<User> newUsers)
{
    users = newUsers;
}

User Data::getCurrentUser()
{
    return currentUser;
}

void Data::setCurrentUser(User newCurrentUser)
{
    currentUser = newCurrentUser;
}

Profile Data::getCurrentProfile()
{
    return currentProfile;
}

void Data::setCurrentProfile(Profile newCurrentProfile)
{
    currentProfile = newCurrentProfile;
}

void Data::addUser(User newCurrentUser)
{
    users.push_back(newCurrentUser);
}

Data::Data() {}
