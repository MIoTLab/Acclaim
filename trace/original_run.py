import math

file_name = 'launchC.txt'
data_all = []
label = 'lennypath'
with open(file_name,'r') as f:
    lines = f.readlines()
    for line in lines:
        if label in line:
            time = int(float(line.split(", ")[0].split('s][')[0].split('[  ')[1]) * 1000000)
            order = int(line.split(", ")[1].split("=")[1])
            data_all.append([time, pow(2,order)])

data = data_all
left = data[0][0]
sampling = int(0.01 * 1000000)
window = int(1 * 1000000)
right = left + window
res = []
res_log = []

while(right <= data[-1][0]):


    _sum = []

    for i in data:

        if i[0] < right and i[0] >= left:
            _sum.append(i[1])
        elif i[0] >= right:
            if len(_sum) != 0:
                res.append(sum(_sum))
                res_log.append(math.log(sum(_sum)))


            else:
                res.append(sum(_sum))
                res_log.append(0)


            left += sampling
            right += sampling
            break


with open("out/launchC_original_0.01_1s.csv",'w') as f:
    for i in res:
        f.write(str(i) + '\n')
with open("out/log_launchC_original_0.01_1s.csv",'w') as f:
    for i in res_log:
        f.write(str(i) + '\n')
