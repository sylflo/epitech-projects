import sys

def     Z_law(list_z, list_conjointe):
    i = 0
    list_z.append(list_conjointe[0])
    list_z.append(list_conjointe[1] + list_conjointe[5])
    list_z.append(list_conjointe[2] + list_conjointe[6] + list_conjointe[10])
    list_z.append(list_conjointe[3] + list_conjointe[7] + list_conjointe[11] + list_conjointe[15])
    list_z.append(list_conjointe[20] + list_conjointe[16] + list_conjointe[12] + list_conjointe[8] + list_conjointe[4])
    list_z.append(list_conjointe[21] + list_conjointe[17] + list_conjointe[13] + list_conjointe[9])
    list_z.append(list_conjointe[22] + list_conjointe[18] + list_conjointe[14])
    list_z.append(list_conjointe[23] + list_conjointe[19])
    list_z.append(list_conjointe[24])

    while i < len(list_z):
        print(round(list_z[i], 3)),
        print ("\t"),
        i += 1
    print("1")

def Y_law(Y, i, list_conjointe, a, b, list_loi_de_y):
    print "Y=",
    print Y,
    print "\t\t",
    X = 10
    sum = 0;
    while X <= 50:
        list_conjointe.append(((a - X) * (b - Y)) / ((5 * a - 150) * (5 * b - 150)))
        X += 10
        print round(list_conjointe[i], 3),
        print "\t",
        sum += list_conjointe[i]
        i += 1
    list_loi_de_y.append(sum)
    print(round(sum, 3))

def X_law(j, main_list, list_loi_de_x):
    sum = 0
    i = j
    while i < 25 + j:
        sum += main_list[i]
        i += 5
    list_loi_de_x.append(sum)
    print round(sum, 3),
    print "\t",

def esperance(list):
    result = 0
    i = 0
    j = 10
    while i <  len(list):
        result += j * list[i]
        j += 10
        i += 1
    print (round(result, 3)) 
    return result

def esperance_z(list):
    result = 0
    i = 0
    j = 20
    while i <  len(list):
        result += j * list[i]
        j += 10
        i += 1
    print (round(result, 3)) 
    return result

def esperance_pow(list):
    result = 0
    i = 0
    j = 10
    while i <  len(list):
        result += pow(j, 2) * list[i]
        j += 10
        i += 1
    return result

def esperance_pow_z(list):
    result = 0
    i = 0
    j = 20
    while i <  len(list):
        result += pow(j, 2) * list[i]
        j += 10
        i += 1
    return result

def parsing():
    if len(sys.argv) != 3:
       print("Veuillez entrer 2 arguments")
       sys.exit()
    if int(sys.argv[1]) <= 50 or int(sys.argv[2]) <= 50:
        print("Veuillez entrez un nombre superieur a 50")
        sys.exit()
    return float(sys.argv[1]), float(sys.argv[2])
