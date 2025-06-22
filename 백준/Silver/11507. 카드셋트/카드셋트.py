S = input()
cards = [S[i : i + 3] for i in range(0, len(S), 3)]
cards_map = {}
for card in cards:
    if card in cards_map:
        print("GRESKA")
        exit()
    cards_map[card] = 1

p = len([k for k in cards_map.keys() if k.startswith("P")])
k = len([k for k in cards_map.keys() if k.startswith("K")])
h = len([k for k in cards_map.keys() if k.startswith("H")])
t = len([k for k in cards_map.keys() if k.startswith("T")])

print(13 - p, 13 - k, 13 - h, 13 - t)
