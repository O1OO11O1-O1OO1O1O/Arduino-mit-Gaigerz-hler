werte = input("Werte?")
haeufigkeiten = {}
eingabeWerte = [werte]
eingabeWerte = werte.split(",")
print("Konvertierte Liste:", eingabeWerte)
print(len(eingabeWerte))

for x in eingabeWerte:

    if x in haeufigkeiten:
        haeufigkeiten[x] += 1
        
    else:
        haeufigkeiten[x] = 1
print(haeufigkeiten)

for zeichen, anzahl in haeufigkeiten.items():
    print(f" '{zeichen}' : {anzahl} mal")