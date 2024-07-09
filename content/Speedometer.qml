import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: speedometer
    width: 300
    height: 300

    property int percentage: 0
    property int sizeCanvas: (width > height) ? height - 20 : width - 20;
    property string colorArc: "red"

    onPercentageChanged: {
        arcCanvas.requestPaint();
    }

    Item {
        id: mainItem
        width: sizeCanvas
        height: sizeCanvas
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter

        Canvas {
            id: arcCanvas
            width: parent.width
            height: parent.height
            anchors.centerIn: parent

            onPaint: {
                var ctx = arcCanvas.getContext("2d");
                ctx.clearRect(0, 0, width, height);

                ctx.beginPath();
                ctx.arc(width / 2, height / 2, width / 2 - 15, 0.85 * Math.PI, 0.15 * Math.PI);
                ctx.lineWidth = 30;
                ctx.strokeStyle = "#000000";
                ctx.stroke();

                var endAngle = 0.85 * Math.PI + (1.3 * Math.PI * (percentage / 100));

                ctx.beginPath();
                ctx.arc(width / 2, height / 2, width / 2 - 15, 0.85 * Math.PI, endAngle);
                ctx.lineWidth = 30;
                ctx.strokeStyle = colorArc;
                ctx.stroke();
            }
        }

    }
}
