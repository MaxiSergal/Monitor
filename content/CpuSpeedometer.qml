import QtQuick 2.15
import QtQuick.Controls 2.15

Speedometer {
    id: cpuspeedometer
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
        width: parent.width
        height: parent.height/100*35
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        Item {
            id: item1
            width: parent.width
            height: parent.height

            Row {
                id: row
                anchors.verticalCenter: parent.verticalCenter
                spacing: cpuspeedometer.width/100*2
                anchors.horizontalCenter: parent.horizontalCenter

                Rectangle {
                    id: tempRectangle
                    width: cpuspeedometer.width/100*29
                    height: cpuspeedometer.height/100*10
                    color: "#656363"
                    radius: 6
                    border.width: 1

                    Text {
                        id: tempText
                        text: qsTr("56 °С")
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: Math.min(width * 0.3, height * 0.7)
                    }
                }

                Rectangle {
                    id: freqRectangle
                    width: cpuspeedometer.width/100*35
                    height: cpuspeedometer.height/100*10
                    color: "#656363"
                    radius: 6

                    border.width: 1
                    Text {
                        id: freqText
                        text: qsTr("3500 MHz")
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: Math.min(width * 0.3, height * 0.7)
                    }
                }

                Rectangle {
                    id: coresRectangle
                    width: cpuspeedometer.width/100*29
                    height: cpuspeedometer.height/100*10
                    color: "#656363"
                    radius: 6
                    border.width: 1
                    Text {
                        id: coresText
                        text: qsTr("12 cores")
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: Math.min(width * 0.3, height * 0.7)
                    }
                }
            }
        }

    }
}
