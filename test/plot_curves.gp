set datafile separator ","
set key autotitle columnhead
set multiplot layout 1,2
set xrange [-1:3]
set yrange [-1:5]

set label 1 "H\\_Quintic" at graph 0.01, 0.05
plot "curves/hermite_quintic.csv" using 1:2 title "Pos"
     "curves/hermite_quintic.csv" using 3:4 title "Vel", \
     "curves/hermite_quintic.csv" using 5:6 title "Acc"

set label 1 "H\\_Cubic" at graph 0.01, 0.05
plot "curves/hermite_cubic.csv" using 1:2 title "Pos"
     "curves/hermite_cubic.csv" using 3:4 title "Vel", \
     "curves/hermite_cubic.csv" using 5:6 title "Acc"
