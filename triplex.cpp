#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty){
    std::cout << "\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    int CodeA = rand() % Difficulty + 1;
    int CodeB = rand() % Difficulty + 1;
    int CodeC = rand() % Difficulty + 1;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "There are 3 numbers in the code\n";
    std::cout << "The codes add-up to: " << CodeSum << std::endl;
    std::cout << "The codes multiple to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check is players guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "Well done agent! You broke this code! Keep going!\n";
        return true;
    }
    else
    {
        std::cout << "You entered the wrong code! Carefull agent! Try again!\n";
        return false;
    }    
}

int main()
{
    srand(time(NULL)); // create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;

    while (LevelDifficulty <= MaxDifficulty) //Loop game untill all levels completed
    {   
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    
    } 

    std::cout << "Great work agent! It's over, You escaped!\n";
    return 0;
}