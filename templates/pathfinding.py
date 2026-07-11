while True:
    read = input()

    print(read)

    if read == "":
        print("No input provided.")

    elif read == "00100" or read == "01110" or read == "00000":
        print("linha reta")

    elif read == "01000" or read == "10000":
        print ("curva leve para esquerda")

    elif read == "00010" or read == "00001":
        print ("curva leve para direita")

    elif read == "01100" or read == "11100":
        print ("curva 90° para esquerda")

    elif read == "00110" or read == "00111":
        print ("curva 90° para direita")