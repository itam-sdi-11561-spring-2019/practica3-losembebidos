# PM_pract_3
Archivos iniciales para la práctica 3 principios de mecatrónica

## Archivos

* pract_3_spi.vhd - Top level entity. Al inicio, escribe a los registros indicados, despues lee de los registros indicados 
* init_accel.vhd - Indica cuáles registros escribir y con qué valores al inicio
* accel_rw.vhd - Recibe los registros a escribir/leer mediante SPI
* spi_3_wire_master.vhd - Componente que maneja la comunicación SPI. Tomado de https://www.digikey.com/eewiki/pages/viewpage.action?pageId=27754638
