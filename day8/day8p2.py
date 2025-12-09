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

    num = len(boxes)

    for d, idx1, idx2 in edges:                   
        if num > 1: 
            id1 = boxes[idx1][1]
            id2 = boxes[idx2][1]                
            
            if id1 != id2:
                if num == 2:
                    res = boxes[idx1][0][0] * boxes[idx2][0][0]
                    print(res)
                else: 
                    for box in boxes:
                        if box[1] == id2:
                            box[1] = id1
            
                num -= 1