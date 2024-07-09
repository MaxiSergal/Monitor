import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: diskSpeedometer
    width: 300
    height: 350

    property int writePercentage: 0
    property int readPercentage: 0
    property int sizeCanvas: (width > height) ? height - 20 : width - 20;
    property string colorArc: "red"

    Text {
        id: percentageText
        text: (writePercentage + "% | " + readPercentage + "%")
        font.pixelSize: 18
        anchors.verticalCenterOffset: -10
        anchors.centerIn: parent
    }

    onWritePercentageChanged: {
        arcWriteCanvas.requestPaint();
    }

    onReadPercentageChanged: {
        arcReadCanvas.requestPaint();
    }

    Item {
        id: mainItem
        width: sizeCanvas
        height: sizeCanvas
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter

        Canvas {
            id: arcMainCanvas
            width: parent.width
            height: parent.height
            anchors.centerIn: parent

            onPaint: {
                var ctx = arcMainCanvas.getContext("2d");
                ctx.clearRect(0, 0, width, height);

                ctx.beginPath();
                ctx.arc(width / 2, height / 2, width / 2 - 15, 0.85 * Math.PI, 0.15 * Math.PI);
                ctx.lineWidth = 30;
                ctx.strokeStyle = "#000000";
                ctx.stroke();
            }
        }

        Canvas {
            id: arcWriteCanvas
            width: parent.width
            height: parent.height
            anchors.centerIn: parent

            onPaint: {
                var ctx = arcWriteCanvas.getContext("2d");
                ctx.clearRect(0, 0, width, height);

                var endAngle = 0.85 * Math.PI + (0.65 * Math.PI * (writePercentage / 100));

                ctx.beginPath();
                ctx.arc(width / 2, height / 2, width / 2 - 15, 0.85 * Math.PI, endAngle);
                ctx.lineWidth = 30;
                ctx.strokeStyle = colorArc;
                ctx.stroke();
            }
        }

        Canvas {
            id: arcReadCanvas
            width: parent.width
            height: parent.height
            anchors.centerIn: parent

            onPaint: {
                var ctx = arcReadCanvas.getContext("2d");
                ctx.clearRect(0, 0, width, height);

                var endAngle = 0.15 * Math.PI - (0.65 * Math.PI * (readPercentage / 100));

                ctx.beginPath();
                ctx.arc(width / 2, height / 2, width / 2 - 15, 0.15 * Math.PI, endAngle, true);
                ctx.lineWidth = 30;
                ctx.strokeStyle = colorArc;
                ctx.stroke();
            }
        }

    }

    Column {
        id: column
        x: 6
        y: 6
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
                anchors.horizontalCenter: parent.horizontalCenter

                spacing: diskSpeedometer.width/100*2
                Rectangle {
                    id: totalRectangle
                    width: diskSpeedometer.width/100*47
                    height: diskSpeedometer.height/100*10
                    color: "#656363"
                    radius: 6
                    border.width: 1
                    Text {
                        id: totalText
                        text: qsTr("255.33 Gb")
                        anchors.fill: parent
                        font.pixelSize: Math.min(width * 0.3, height * 0.7)
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }

                Rectangle {
                    id: freeRectangle
                    width: diskSpeedometer.width/100*47
                    height: diskSpeedometer.height/100*10
                    color: "#656363"
                    radius: 6
                    border.width: 1
                    Text {
                        id: freeText
                        text: qsTr("458.64 Gb")
                        anchors.fill: parent
                        font.pixelSize: Math.min(width * 0.3, height * 0.7)
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }

            }
        }
    }
}
