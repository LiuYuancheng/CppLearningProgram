ip link set wg0 down
ip link delete wg0
ip link add wg0 type wireguard
ip addr add 10.0.0.1/24 dev wg0
wg set wg0 private-key ./Bob_privkey listen-port 50000
ip link set wg0 up

wg set wg0 peer muFZtgJrx0d/gF1fDtGMo5ZALUR+WYlffU7hwHguRlU= allowed-ips 10.0.0.2/32 endpoint 192.168.18.20:50000
echo 'module wireguard +p' | sudo tee /sys/kernel/debug/dynamic_debug/control