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


#concurrency
data_dict = {}
data_list = []
for i in data_all:
    if i[0] not in data_dict:
        data_dict[i[0]] = i[1]
        data_list.append(i)

#sampling
left = int(data_list[0][0])
sampling = int(0.01 * 1000000)
right = int(left + sampling)
count = int((data_list[-1][0] - data_list[0][0]) / sampling)

time = {}
time_set = []
non_zero = 0
zero = 0
for i in range(count):

    time_set.append(right)

    if right not in time:
        for j in data_list:
            if j[0] < left:
                continue
            if j[0] >= left and j[0] < right:
                time[right] = j
                non_zero += 1
                break
            else:
                time[right] = [left, 0]
                zero += 1
                break
        right += sampling
        left += sampling


data_sampling = []
for i in time:
    data_sampling.append(time[i])


data = data_sampling
left = data[0][0]
window = 1 * 1000000
right = left + window
res = []

while(right<data[-1][0]):
    _sum = []

    for i in range(len(data)):

        if data[i][0] < left:
            continue
        if data[i][0] >= left and data[i][0] < right:
            _sum.append(data[i][1])
            #print(data[i][0])

        elif data[i][0] >= right:
            if sum(_sum) != 0:
                #print(_sum)
                res.append(math.log(sum(_sum)))
            else:
                res.append(sum(_sum))


            left += sampling
            right += sampling
            break


with open("out/log_launchC_samp_0.01_1.0s.csv",'w') as f:
    for i in res:
        f.write(str(i) + '\n')
