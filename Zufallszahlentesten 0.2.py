werte = input("Werte?")
haeufigkeiten = {}
eingabeWerte = [werte]
eingabeWerte = werte.split(",")
durchschnit = 0

print(len(eingabeWerte), "Zeichen")

for x in eingabeWerte:
    durchschnit = durchschnit +int(x)

    if x in haeufigkeiten:
        haeufigkeiten[x] += 1
        
    else:
        haeufigkeiten[x] = 1
print(haeufigkeiten)

for zeichen, anzahl in haeufigkeiten.items():
    print(f" '{zeichen}' : {anzahl} mal", 100 /len(eingabeWerte) *anzahl, "%")

print("Durchschnit:", durchschnit /len(eingabeWerte))