typedef struct
{
    char *name, *password;
    int score;
} Player;

Player login();
Player newAccount();