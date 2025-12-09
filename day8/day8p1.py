import sys
import math
from collections import Counter

def distance(box1, box2):
    x1, y1, z1 = box1[0]
    x2, y2, z2 = box2[0]

    return math.sqrt((x1 - x2) ** 2 +
                     (y1 - y2) ** 2 +
                     (z1 - z2) ** 2)

if __name__ == "__main__":
    data = sys.stdin.readlines()
    boxes = []

    for i, line in enumerate(data):
        parts = line.strip().split(',')
        coords = (int(parts[0]), int(parts[1]), int(parts[2]))
        box = [coords, i] 
        boxes.append(box)

    edges = []

    for i in range(len(boxes)):
        for j in range(i + 1, len(boxes)):
            edges.append((distance(boxes[i], boxes[j]), i, j))

    edges.sort()

    for d, idx1, idx2 in edges[:1000]:        
        id1 = boxes[idx1][1]
        id2 = boxes[idx2][1]
        
        if id1 != id2:
            for box in boxes:
                if box[1] == id2:
                    box[1] = id1

    index = Counter(box[1] for box in boxes)
    top_3 = index.most_common(3)
    result = top_3[0][1] * top_3[1][1] * top_3[2][1]
    print(result)
        