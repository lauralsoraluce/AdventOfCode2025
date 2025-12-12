import sys
import re
import itertools

if __name__ == "__main__":
    data = sys.stdin.readlines()
    machines = []

    for line in data:
        parts = line.strip()
        lights_string = re.search(r'\[(.*?)\]', line).group(1)
    
        light = int((lights_string.replace('#', '1').replace('.', '0'))[::-1],2)

        buttons_string = re.findall(r'\((.*?)\)', line)
        
        buttons = []
        for b in buttons_string:
            bitset = 0

            for num in b.split(','):
                bitset |= (1 << int(num))
            buttons.append(bitset)

        machines.append((light, buttons))

    total_presses = 0
    for machine in machines:
        light, buttons = machine
        found = False

        if light != 0:
            for k_ops in range(1, len(buttons) + 1):
                
                for combo in itertools.combinations(buttons, k_ops):
                    
                    current_light = 0
                    for btn in combo:
                        current_light ^= btn
                    
                    if current_light == light:
                        total_presses += k_ops
                        found = True
                        break
                
                if found:
                    break

    print(total_presses)