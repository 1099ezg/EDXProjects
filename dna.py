import csv
import sys
from sys import argv


def main():
    #  Check for command-line usage
    if len(argv) != 3:
        print("Usage: python3 dna.py (file).csv (sequence).txt")
        exit()
    # open file
    with open(argv[1]) as e:
        reader = csv.reader(e)
        database = list(reader)
    #: Read DNA sequence file into a variable
    dna_sequence = argv[2]

    # read contents
    with open(dna_sequence, "r") as sequence_file:
        dna = sequence_file.read()
    # Find longest match of each STR in DNA sequence
    matches = []
    for i in range(1, len(database[0])):
        matches.append(longest_match(dna, database[0][i]))
    # Check database for matching profiles
    profile = "No Match"
    profile_counter = 0

    for i in range(1, len(database)):
        for j in range(len(matches)):
            if int(matches[j]) == int(database[i][j + 1]):
                profile_counter += 1
        if profile_counter == len(matches):
            profile = database[i][0]
            break
        else:
            profile_counter = 0
    print(profile)
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
