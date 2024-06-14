Proyek ini menunjukkan cara menggunakan ESP32 untuk membaca data dari sensor gas MQ dan sensor suhu serta kelembapan DHT11, kemudian mengirimkan data tersebut ke server Flask.

## Komponen yang Digunakan
ESP32 Development Board
Sensor Gas MQ (Flying Fish)
Sensor Suhu dan Kelembapan DHT11

## Koneksi
### Sensor MQ (Flying Fish)
VCC ke 5V (atau 3.3V, tergantung spesifikasi sensor)
GND ke Ground
D0 (Digital Output) ke D19 (pin digital pada ESP32)

### Sensor DHT11
Data Pin ke D4
VCC ke 3.3V atau 5V
GND ke Ground

## Langkah-langkah Menjalankan Proyek
### Setup ESP32:
Upload kode ke board ESP32 Anda.
Pastikan ESP32 terhubung ke jaringan yang sama dengan server Flask Anda.

### Pengaturan Koneksi:
Pastikan semua kabel dan koneksi sensor sudah sesuai dengan skema yang diberikan.


## Transmisi Data:
ESP32 akan membaca data dari sensor MQ dan DHT11 kemudian mengirimkan data tersebut ke server Flask setiap 60 detik.

## Troubleshooting
Pastikan semua koneksi aman dan benar.
Verifikasi kredensial WiFi.
Periksa apakah alamat IP server Flask dikonfigurasi dengan benar di kode ESP32.
Jika pembacaan sensor MQ selalu menunjukkan 0, pastikan sensor terhubung dengan benar dan sudah cukup waktu pemanasan
