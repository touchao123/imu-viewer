/*
 *    This application is visualizes data from imu-utils over tcp
 *
 *    Copyright (C) 2013 Simon Stürz (stuerz.simon@gmail.com)
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <QApplication>
#include <GLUT/glut.h>

#include <core.h>

#include <QJsonDocument>

void serializeAllData(const QVector3D &accData, const QVector3D &gyroData, const QVector3D &magData, const QVector3D &angles, const int &dt)
{
    QVariantMap message;

    QVariantMap accMap;
    accMap.insert("x",accData.x());
    accMap.insert("y",accData.y());
    accMap.insert("z",accData.z());

    QVariantMap gyroMap;
    gyroMap.insert("x",gyroData.x());
    gyroMap.insert("y",gyroData.y());
    gyroMap.insert("z",gyroData.z());

    QVariantMap magMap;
    magMap.insert("x",magData.x());
    magMap.insert("y",magData.y());
    magMap.insert("z",magData.z());

    QVariantMap angleMap;
    angleMap.insert("roll",angles.x());
    angleMap.insert("pitch",angles.y());
    angleMap.insert("yaw",angles.z());

    message.insert("acc",accMap);
    message.insert("gyr",gyroMap);
    message.insert("mag",magMap);
    message.insert("angles",angleMap);
    message.insert("dt",dt);

    QByteArray data = QJsonDocument::fromVariant(message).toJson();
    data.append("\n");
    qDebug()<<data;

//    emit dataTcpReady(data);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    Core core;
    QVector3D acc;
    acc.setX(1.0);
    acc.setY(1.1);
    acc.setZ(1.2);
    QVector3D gyro;
    gyro.setX(2.0);
    gyro.setY(2.1);
    gyro.setZ(2.2);
    QVector3D mag;
    mag.setX(3.0);
    mag.setY(3.1);
    mag.setZ(3.2);
    QVector3D angle;
    angle.setX(4.0);
    angle.setY(4.1);
    angle.setZ(4.2);
    int dt = 1;

    serializeAllData(acc,gyro,mag,angle,dt);
    return a.exec();
}
