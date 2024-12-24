scores = {}
fd = open("results.txt")
for line in fd:
    name, score = line.split(" ")
    scores[name] = score
fd.close()
for w in sorted(scores, key = scores.get, reverse = True):
    print(w, scores[w])

