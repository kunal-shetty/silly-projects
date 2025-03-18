import random

tries = 5
num = random.randint(1, 100)
guess = int(input("Enter your number lying between 1-100: "))

while tries > 1:
    if guess == num:
        print("Congratulations, You have guessed the number")
        print(f"Remaining tries: {tries}")
        break
    elif guess > num:
        print("Your guess was too high, try again")
    else:
        print("Your guess was too low, try again")

    tries -= 1
    print(f"Remaining tries: {tries}")
    guess = int(input())

if guess != num:
    print("You have failed to guess the number")
    print(f"The number was {num}")
