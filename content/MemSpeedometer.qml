import QtQuick 2.15
import QtQuick.Controls 2.15

Speedometer {
    id: memspeedometer
    width: 300
    height: 300
    percentage: 0

    Text {
        id: percentageText
        text: (percentage + "%")
        font.pixelSize: 24
        anchors.verticalCenterOffset: -20
        anchors.centerIn: parent
    }

    Column {
        id: column
        x: -4
        y: -4
        width: parent.width
        height: parent.height/100*35
        anchors.bottom: parent.bottom
        Item {
            id: item1
            width: parent.width
            height: parent.height
            Row {
                id: row
                anchors.verticalCenter: parent.verticalCenter
                spacing: memspeedometer.width/100*2
                Rectangle {
                    id: totalRectangle
                    width: memspeedometer.width/100*31
                    height: memspeedometer.height/100*10
                    color: "#656363"
                    radius: 6
                    border.width: 1
                    Text {
                        id: totalText
                        text: qsTr("50.6 Gb")
                        anchors.fill: parent
                        font.pixelSize: Math.min(width * 0.3, height * 0.7)
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }

                Rectangle {
                    id: freeRectangle
                    width: memspeedometer.width/100*31
                    height: memspeedometer.height/100*10
                    color: "#656363"
                    radius: 6
                    border.width: 1
                    Text {
                        id: freeText
                        text: qsTr("44.6 Gb")
                        anchors.fill: parent
                        font.pixelSize: Math.min(width * 0.3, height * 0.7)
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }

                Rectangle {
                    id: usedRectangle
                    width: memspeedometer.width/100*31
                    height: memspeedometer.height/100*10
                    color: "#656363"
                    radius: 6
                    border.width: 1
                    Text {
                        id: usedText
                        text: qsTr("5.4 Gb")
                        anchors.fill: parent
                        font.pixelSize: Math.min(width * 0.3, height * 0.7)
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
