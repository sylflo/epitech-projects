import math

class Algo:
    
    def __init__(self, nb_1, list_dice, nb_2 = 0):
        self.nb_1 = nb_1
        self.nb_2 = nb_2
        self.list_dice = list_dice

    def occ_nb_1(self):
        j = 0
        for i in self.list_dice:
            if self.nb_1 == i:
                j += 1
        return j

    def occ_nb_2(self):
        j = 0
        for i in self.list_dice:
            if self.nb_2 == i:
                j += 1
        return j
        
    def paire(self):
        i = self.occ_nb_1()
        p = 1 / 6
        if i >= 2:
            print("probabilite d'obtenir une paire de {}: 100%" .format(self.nb_1)) 
            return
        i += 1
        while i < 2:
            p *= 1/6
            i += 1
        i = self.occ_nb_1()
        x = 2 - i
        y = 5 - i
        result = math.factorial(y) / (math.factorial(x) * math.factorial(y - x))
        result *= p
        result = result - ((2 - 1) / (pow(6, 2)))
        percent = result * 100
        print("probabilite d'obtenir une paire de {}: {}%" .format(self.nb_1, round(percent, 2)))  
        return result

    def brelan(self):
        i = self.occ_nb_1()
        p = 1 / 6
        if i >= 3:
            print("probabilite d'obtenir un brelan de {}: 100%" .format(self.nb_1))  
            return
        i += 1
        while i < 3:
            p *= 1/6
            i += 1
        i = self.occ_nb_1()
        x = 3 - i
        y = 5 - i
        result = math.factorial(y) / (math.factorial(x) * math.factorial(y - x))
        result *= p
        result = result - ((3 - 1) / (pow(6, 3)))
        percent = result * 100
        print("probabilite d'obtenir un brelan de {}: {}%" .format(self.nb_1, round(percent, 2)))  
        return result

    def carre(self):
        i = self.occ_nb_1()
        p = 1 / 6
        if i >= 4:
            print("probabilite d'obtenir un carre de {}: 100%" .format(self.nb_1))  
            return
        i += 1
        while i < 4:
            p *= 1/6
            i += 1
        i = self.occ_nb_1()
        x = 4 - i
        y = 5 - i
        result = math.factorial(y) / (math.factorial(x) * math.factorial(y - x))
        result *= p
        result = result - ((4 - 1) / (pow(6, 4)))
        result *= 100
        print("probabilite d'obtenir un carre de {}: {}%" .format(self.nb_1, round(result, 2)))  

    def yams(self):
        print("probabilite d'obtenir un yams de {}: {}%" .format(self.nb_1, round(pow(1/6, (5 - self.occ_nb())) * 100, 2)))  

    def full(self):
        nb_1 = self.occ_nb_1() 
        


        
        
