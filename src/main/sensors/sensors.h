/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

typedef enum {
    SENSOR_INDEX_GYRO = 0,
    SENSOR_INDEX_ACC,
    SENSOR_INDEX_BARO,
    SENSOR_INDEX_MAG,
    SENSOR_INDEX_RANGEFINDER,
    SENSOR_INDEX_PITOT,
    SENSOR_INDEX_COUNT
} sensorIndex_e;

typedef struct int16_flightDynamicsTrims_s {
    int16_t roll;
    int16_t pitch;
    int16_t yaw;
} flightDynamicsTrims_def_t;

typedef union flightDynamicsTrims_u {
    int16_t raw[3];
    flightDynamicsTrims_def_t values;
} flightDynamicsTrims_t;

#define CALIBRATING_GYRO_CYCLES             1000
#define CALIBRATING_ACC_CYCLES              400
#define CALIBRATING_BARO_CYCLES             200 // 10 seconds init_delay + 200 * 25 ms = 15 seconds before ground pressure settles
#define CALIBRATING_PITOT_CYCLES            200

// These bits have to be aligned with sensorIndex_e
typedef enum {
    SENSOR_GYRO = 1 << 0, // always present
    SENSOR_ACC = 1 << 1,
    SENSOR_BARO = 1 << 2,
    SENSOR_MAG = 1 << 3,
    SENSOR_SONAR = 1 << 4,
    SENSOR_PITOT = 1 << 5,
    SENSOR_GPS = 1 << 6,
    SENSOR_GPSMAG = 1 << 7,
} sensors_e;

typedef enum {
    ALIGN_DEFAULT = 0,                                      // driver-provided alignment
    CW0_DEG = 1,
    CW90_DEG = 2,
    CW180_DEG = 3,
    CW270_DEG = 4,
    CW0_DEG_FLIP = 5,
    CW90_DEG_FLIP = 6,
    CW180_DEG_FLIP = 7,
    CW270_DEG_FLIP = 8
} sensor_align_e;

typedef struct sensorAlignmentConfig_s {
    sensor_align_e gyro_align;              // gyro alignment
    sensor_align_e acc_align;               // acc alignment
    sensor_align_e mag_align;               // mag alignment
} sensorAlignmentConfig_t;

typedef struct sensorSelectionConfig_s {
    uint8_t acc_hardware;                   // Which acc hardware to use on boards with more than one device
    uint8_t baro_hardware;                  // Barometer hardware to use
    uint8_t mag_hardware;                   // Which mag hardware to use on boards with more than one device
    uint8_t pitot_hardware;                 // Pitotmeter hardware to use
} sensorSelectionConfig_t;

typedef struct sensorTrims_s {
    flightDynamicsTrims_t accZero;          // Accelerometer offset
    flightDynamicsTrims_t accGain;          // Accelerometer gain to read exactly 1G
    flightDynamicsTrims_t magZero;          // Compass offset
} sensorTrims_t;

