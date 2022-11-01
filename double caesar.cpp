#include <iostream>
#include <windows.h>

using namespace std;

// A mod function that is "safe" to use even when val might be negative
int safemod(int val, int mod)
{
	int modval = val % mod;
	if (modval < 0)
	{
		modval += mod;
	}
	return modval;
}

/**
	Encryption function starts here
*/
string encrypt(string message, string key)
{
	const int maxChar = 'z';
	const int minChar = ' ';
	const int charRange = 1 + maxChar - minChar;
	string charstr;
	string result;
	int tempVal = 0;
	int j = 0; // used to index key string
	int i = 0; // used to index message string
	int k = 0;

	// get all the characters in a variable
	for (i = minChar; i <= maxChar; i++)
	{
		charstr += char(i);
	}

	for (i = 0; i < message.length(); i++)
	{
		if (j == key.length())
		{
			j = 0;
		}

		tempVal = (int(message[i]) - minChar) + (int(key[j]) - minChar);
		result += charstr[safemod(tempVal, charRange)];

		j++;
	}
	return result;
}

/**
	Decryption function starts here
*/
string decrypt(string message, string key)
{
	const int maxChar = 'z';
	const int minChar = ' ';
	const int charRange = 1 + maxChar - minChar;
	string charstr;
	string result;
	int tempVal = 0;
	int j = 0; // used to index key string
	int i = 0; // used to index message string
	int k = 0;

	// get all the characters in a variable
	for (i = minChar; i <= maxChar; i++)
	{
		charstr += char(i);
	}

	for (i = 0; i < message.length(); i++)
	{
		if (j == key.length())
		{
			j = 0;
		}

		tempVal = (int(message[i]) - minChar) - (int(key[j]) - minChar);
		result += charstr[safemod(tempVal, charRange)];

		j++;
	}
	return result;
}

int main()
{
	string message;
	string key;
	char ans;
	char command = '-';

	cout << "========================================================\n";
	cout << "                          Welcome                       \n";
	cout << "========================================================\n\n";

	while (command != 'q' && command != 'Q')
	{
		cout << "\n\nWhich of the operation would you like to perform? \nTo quit operation Q \nTo Encrypt press E. \nTo Decrypt press D \n\t>> ";
		cin >> ans;
		command = ans;

		if (ans == 'E' || ans == 'e')
		{
			cout << "Enter the message you want to encrypt: \n\t>> ";
			cin.ignore();
			getline(cin, message);

			cout << "Enter your encryption key: \n\t>> ";
			cin.ignore();
			getline(cin, key);

			cout << "\n\n";
			cout << "========================================================\n";
			cout << "                  Your Encrypted message                \n";
			cout << "========================================================\n\n";

			cout << encrypt(message, key);
		}

		else if (ans == 'D' || ans == 'd')
		{
			cout << "Enter the message you want to decrypt: \n\t>> ";
			cin.ignore();
			getline(cin, message);

			cout << "Enter your decryption key: \n\t>> ";
			cin.ignore();
			getline(cin, key);

			cout << "\n\n";
			cout << "========================================================\n";
			cout << "                  Your decrypted message                \n";
			cout << "========================================================\n\n";

			cout << decrypt(message, key);
		}
		else
		{
			cout << "Invalid argument! try again.";
			system("CLS");
		}
	}
}
