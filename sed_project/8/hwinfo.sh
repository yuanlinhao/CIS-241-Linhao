lscpu ｜ sed -ne '/^CPU(s):/p'
echo "======="
echo "Memory:"
free -h | sed -ne '1p' -ne '/^Mem:/p' -e 's/Gi/ Gigabytes/g'
echo "======="
echo "Disks:"
echo "======"
df -h | sed -ne '/[0-9]\{1,3\}Ti/p'
echo "Date:"
echo "====="
date | sed -f date.sed