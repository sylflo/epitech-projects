#!/bin/python3

import sys

class My_exception(Exception):
    def __init__(self, reason):
        self.reason = reason

    def __str__(self):
        return self.reason

    def test(self):
        return self.reason

def check_nb(nb):
    if nb < 0 or nb > 6:
        raise My_exception("Veuillez entrer un nombre compris entre 0 et 6")
    else:
        return nb


def check_error():
    if len(sys.argv) != 7:
        print("Veuillez entrer 6 argument");
        sys.exit();

    nb_zero = 0
    i = 1
    while i < len(sys.argv) - 1:
        try:
            check_nb(int(sys.argv[i]))
            if int(sys.argv[i]) == 0:
                nb_zero += 1
   
        except ValueError:
            print(sys.argv[i], "- Veuillez entrez un nombre entier")
            sys.exit(0)
        except My_exception as e:
            print(e.reason)
            sys.exit(0)

        i += 1
    


    if nb_zero !=0 and nb_zero != 5:
        print("Toutes les valeurs doivent etre nulles")
        sys.exit(0)

    try:
        sys.argv[i]
    except ValueError:
        print(sys.argv[i], "- Veuillez entrez une chaine de caracteres");

    tuple_proba = ("paire_1", "paire_2", "paire_3", "paire_4", "paire_5", "paire_6",
               "brelan_1", "brelan_2", "brelan_3", "brelan_4", "brelan_5", "brelan_6",
               "carre_1", "carre_2", "carre_3", "carre_4", "carre_5", "carre_6",
               "suite_1", "suite_2", "suite_3", "suite_4", "suite_5", "suite_6",
               "yams_1", "yams_2", "yams_3", "yams_4", "yams_5", "yams_6",
                "full_1_2",  "full_1_3", "full_1_4", "full_1_5", "full_1_6",
                "full_2_1", "full_2_3", "full_2_4", "full_2_5", "full_2_5",
                "full_3_1", "full_3_2", "full_3_4", "full_3_5", "full_3_6", 
                "full_4_1", "full_4_2", "full_4_3", "full_4_5", "full_4_6", 
                "full_5_1", "full_5_2", "full_5_3", "full_5_4", "full_5_6", 
                "full_6_1", "full_6_2", "full_6_3", "full_6_4", "full_6_5", 
    );

    check_proba = False;
    for str in tuple_proba:
        if str == sys.argv[i]:
            check_proba = True

    if check_proba == False:
        print("Veuillez entrez une chaine de caractere correcte")
        sys.exit(0);
    return sys.argv[i]
