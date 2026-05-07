namespace hellmath {

// Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
enum AccountStatus{
    troll,
    guest,
    user,
    mod
};

// Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
enum Action {
    read,
    write,
    remove
};

// Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
bool display_post(AccountStatus statusPost, AccountStatus statusView)
{
    switch(statusPost)
    {
        case  AccountStatus::troll:
            return statusView == AccountStatus::troll;
        default:
            return true;
    }
}
    
// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
bool permission_check(Action action, AccountStatus status)
{
    switch (status)
    {        
        case AccountStatus::guest:
            return action == Action::read;
        case AccountStatus::troll:
        case AccountStatus::user:
            return action != Action::remove;
        case AccountStatus::mod:
            return true;
    }
    return false;
}
    
// Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
bool valid_player_combination(AccountStatus p1Stat, AccountStatus p2Stat) {
    if (p1Stat == AccountStatus::troll || p2Stat == AccountStatus::troll) { return p1Stat == p2Stat; } // Trolls can only play with other trolls
    if (p1Stat > AccountStatus::guest) { return p2Stat >= AccountStatus::user; } // Mods can only play with users and mods

    // Default for mismatched users, or guests attempting to start a game
    return false;
}

// Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
bool has_priority(AccountStatus a, AccountStatus b) {
    return a > b;
}
    
}  // namespace hellmath
