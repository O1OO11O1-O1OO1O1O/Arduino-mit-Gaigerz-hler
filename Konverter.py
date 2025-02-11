abc = ["A", "Ä", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "Ö", "P", "Q", "R", "S", "T", "U", "Ü", "V", "W", "X", "Y", "Z", "a", "ä", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "ö", "p", "q", "r", "s", "t", "u", "ü", "v", "w", "x", "y", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "!", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", ":", ";", "<", "=", ">", "?", "@", "[", "]", "^", "_", "ß", "{", "|", "}", "~", " ", "°"]

speicher2 = []

with open(r'E:\1_Marten\Jugend Forscht\2025\Code\Zufallszahlen\SPEICHER(Gute Zufallszahlen).TXT', 'r') as speicher:
    Gesamtspeicher = speicher.read()
    print(Gesamtspeicher)
    print(len(Gesamtspeicher))

    for x in range(0, len(Gesamtspeicher), 2):
        zeichen = Gesamtspeicher[x:x+2]
        speicher2.append(abc[int(zeichen)])

#print(speicher2)

with open(r'E:\1_Marten\Jugend Forscht\2025\Code\Zufallszahlen\SPEICHER(Gute Zufallszahlen).TXT', 'w') as speicher:
    speicher.write("".join(speicher2))

with open(r'E:\1_Marten\Jugend Forscht\2025\Code\Zufallszahlen\SPEICHER(Gute Zufallszahlen).TXT', 'r') as speicher:
    Gesamtspeicher = speicher.read()
    print(Gesamtspeicher)


        