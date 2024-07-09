// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.5
import QtQuick.Controls 6.5

Window
{
    property int sizeW: 200
    property int sizeH: 800
    property bool isStuck: false

    id: window
    visible: true
    color: "transparent"
    width: sizeW
    height: sizeH
    opacity: 1
    minimumWidth: sizeW
    minimumHeight: sizeH

    flags: Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint

    title: "Resource Monitor"

    Rectangle
    {
        id: mainRect
        visible: true
        color: "#484848"
        radius: 15
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0


        Rectangle
        {
            id: titleBar
            x: 0
            y: 15
            width: parent.width
            height: 30
            opacity: 0.6
            color: "#7a7a7a"
            radius: 15
            anchors.top: parent.top
            anchors.topMargin: 0

            // Кнопка закрытия

            MouseArea
            {
                id: windowDragArea
                anchors.fill: parent
                onPressed:
                {
                    dragX = mouseX;
                    dragY = mouseY;
                    mouseAreaPressed = true
                }

                onPositionChanged:
                {
                    if (mouseAreaPressed)
                    {
                        //                        window.x += mouseX - dragX;
                        //                        window.y += mouseY - dragY;
                    }
                }

                onReleased:
                {
                    mouseAreaPressed = false

                    //                    var screenWidth = Screen.width;
                    //                    var screenHeight = Screen.height;
                    //                    var snapMargin = 150;

                    //                    if (window.x < snapMargin) {
                    //                        window.x = 0;
                    //                        window.isStuck = true;
                    //                    } else if (window.x + window.width > screenWidth - snapMargin) {
                    //                        window.x = screenWidth - window.width;
                    //                        window.isStuck = true;
                    //                    }
                    //                    else
                    //                        window.isStuck = false;

                    //                    if (window.y < snapMargin) {
                    //                        window.y = 0;
                    //                        window.isStuck = true;
                    //                    } else if (window.y + window.height > screenHeight - snapMargin) {
                    //                        window.y = screenHeight - window.height;
                    //                        window.isStuck = true;
                    //                    }
                    //                    else
                    //                        window.isStuck = false;

                    //                if(window.isStuck)
                    //                {
                    //                    if (window.x <= 0) {
                    //                        window.width = sizeW;
                    //                        window.height = sizeH;
                    //                    }
                    //                    else if (window.x + window.width >= Screen.width)
                    //                    {
                    //                        window.width = sizeW;
                    //                        window.height = sizeH;
                    //                    }
                    //                    else if (window.y - 30 <= 0)
                    //                    {
                    //                        window.width = sizeH;
                    //                        window.height = sizeW;
                    //                    }
                    //                    else if (window.y + window.height >= Screen.height)
                    //                    {
                    //                        window.width = sizeH;
                    //                        window.height = sizeW;
                    //                    }
                    //                    else
                    //                    {
                    //                        window.width = sizeW;
                    //                        window.height = sizeH;
                    //                    }
                    //                }
                    //                else
                    //                {
                    //                    window.width = sizeW;
                    //                    window.height = sizeH;
                    //                }
                }

                property bool mouseAreaPressed: false
                property int dragX: 0
                property int dragY: 0
                opacity: 1
            }

            Row
            {
                id: row
                x: 0
                y: 0
                width: parent.width
                height: parent.height
                rightPadding: 10
                enabled: true
                spacing: 5
                layoutDirection: Qt.RightToLeft

                Button
                {
                    id: exitButton
                    text: "X"
                    anchors.verticalCenter: parent.verticalCenter
                    width: 25
                    height: 25
                    visible: true
                    onClicked: Qt.quit()

                    background: Rectangle
                    {
                        color: "#adadad"
                        radius: 7
                        gradient: Gradient
                        {
                            GradientStop
                            {
                                id: gradientStop_exitButton
                                position: 0
                                color: "#adadad"
                            }

                            GradientStop
                            {
                                id: gradientStop1_exitButton
                                position: 1
                                color: "#adadad"
                            }

                            orientation: Gradient.Vertical
                        }
                    }

                    states: [
                        State
                        {
                            name: "hovered"
                            when: exitButton.hovered && !exitButton.pressed
                            PropertyChanges
                            {
                                target: gradientStop_exitButton
                                color: "#e3e3e3"
                            }

                            PropertyChanges
                            {
                                target: gradientStop1_exitButton
                                color: "#525252"
                            }
                        },
                        State
                        {
                            name: "pressed"
                            when: exitButton.pressAndHold && exitButton.hovered
                            PropertyChanges
                            {
                                target: gradientStop_exitButton
                                color: "#e3e3e3"
                            }

                            PropertyChanges
                            {
                                target: gradientStop1_exitButton
                                color: "#525252"
                            }

                            PropertyChanges
                            {
                                target: exitButton
                                scale: 0.9
                            }
                        }
                    ]
                }


                Button
                {
                    id: collapseButton
                    text: "-"
                    anchors.verticalCenter: parent.verticalCenter
                    width: 25
                    height: 25
                    visible: true
                    onClicked: window.showMinimized()

                    background: Rectangle
                    {
                        color: "#adadad"
                        radius: 7
                        gradient: Gradient
                        {
                            GradientStop
                            {
                                id: gradientStop_collapseButton
                                position: 0
                                color: "#adadad"
                            }

                            GradientStop
                            {
                                id: gradientStop1_collapseButton
                                position: 1
                                color: "#adadad"
                            }

                            orientation: Gradient.Vertical
                        }
                    }

                    states: [
                        State
                        {
                            name: "hovered"
                            when: collapseButton.hovered && !collapseButton.pressed
                            PropertyChanges
                            {
                                target: gradientStop_collapseButton
                                color: "#e3e3e3"
                            }

                            PropertyChanges
                            {
                                target: gradientStop1_collapseButton
                                color: "#525252"
                            }
                        },
                        State
                        {
                            name: "pressed"
                            when: collapseButton.pressAndHold && collapseButton.hovered
                            PropertyChanges
                            {
                                target: gradientStop_collapseButton
                                color: "#e3e3e3"
                            }

                            PropertyChanges
                            {
                                target: gradientStop1_collapseButton
                                color: "#525252"
                            }

                            PropertyChanges
                            {
                                target: collapseButton
                                scale: 0.9
                            }
                        }
                    ]
                }

            }





        }

        Column
        {
            id: column
            x: 0
            y: 36
            width: 200
            height: 737
            spacing: 15
            topPadding: 1

            Rectangle
            {
                id: memRectangle
                width: parent.width - 10;
                height: 200
                opacity: 1
                color: "#666666"
                radius: 10
                anchors.horizontalCenter: parent.horizontalCenter

                MemSpeedometer {
                    id: memSpeedometer
                    anchors.fill: parent
                }
            }

            Rectangle
            {
                id: diskRectangle
                width: parent.width - 10
                height: 200
                opacity: 1
                color: "#666666"
                radius: 10
                anchors.horizontalCenter: parent.horizontalCenter

                DiskSpeedometer {
                    id: diskSpeedometer
                    anchors.fill: parent
                }
            }

            Rectangle
            {
                id: cpuRectangle
                width: parent.width - 10;
                height: 200
                opacity: 1
                color: "#666666"
                radius: 10
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: parent.horizontalCenter

                CpuSpeedometer {
                    id: cpuSpeedometer
                    anchors.fill: parent
                }
            }


        }

        Button {
            Timer
            {
                id: timerUp
                interval: 100
                repeat: true
                onTriggered:
                {
                    if(cpuSpeedometer.percentage < 100)
                        cpuSpeedometer.percentage++;
                    else
                        timer.stop();
                    if(memSpeedometer.percentage < 100)
                        memSpeedometer.percentage++;
                    else
                        timer.stop();

                    if(diskSpeedometer.writePercentage < 100)
                        diskSpeedometer.writePercentage++;
                    else
                        timer.stop();
                    if(diskSpeedometer.readPercentage < 100)
                        diskSpeedometer.readPercentage++;
                    else
                        timer.stop();
                }
            }
            id: button
            x: 17
            y: 703
            width: 75
            height: 40
            text: qsTr("Up")

            onPressed:
            {
                timerUp.start()
            }
            onReleased:
            {
                timerUp.stop()
            }
        }

        Button {
            Timer
            {
                id: timerDown
                interval: 100
                repeat: true
                onTriggered:
                {
                    if(cpuSpeedometer.percentage > 0)
                        cpuSpeedometer.percentage--;
                    else
                        timer.stop();
                    if(memSpeedometer.percentage > 0)
                        memSpeedometer.percentage--;
                    else
                        timer.stop();
                    if(diskSpeedometer.writePercentage > 0)
                        diskSpeedometer.writePercentage--;
                    else
                        timer.stop();
                    if(diskSpeedometer.readPercentage > 0)
                        diskSpeedometer.readPercentage--;
                    else
                        timer.stop();
                }
            }
            id: button1
            x: 109
            y: 703
            width: 75
            height: 40
            text: qsTr("Down")

            onPressed:
            {
                timerDown.start()
            }

            onReleased:
            {
                timerDown.stop()
            }
        }



    }

    //    StateGroup {
    //        id: titleBarButtonsStates
    //        state: ""
    //        states: [
    //            State {
    //                name: "hoveredCollapseButtonState"
    //                when: collapseButton.hovered
    //                PropertyChanges {
    //                    target: gradientStop_collapseButton
    //                    color: "#e3e3e3"
    //                }

    //                PropertyChanges {
    //                    target: gradientStop1_collapseButton
    //                    color: "#525252"
    //                }
    //            },
    //            State {
    //                name: "pressedCollapseButtonState"
    //                when: collapseButton.focus
    //                PropertyChanges {
    //                    target: gradientStop_collapseButton
    //                    color: "#e3e3e3"
    //                }

    //                PropertyChanges {
    //                    target: gradientStop1_collapseButton
    //                    color: "#525252"
    //                }

    //                PropertyChanges {
    //                    target: collapseButton
    //                    width: 21
    //                    height: 21
    //                }
    //            },
    //            State {
    //                name: "releasedCollapseButtonState"
    //                when: collapseButton.released
    //            },

    //            State {
    //                name: "hoveredExitButtonState"
    //                when: exitButton.hovered
    //                PropertyChanges {
    //                    target: gradientStop_exitButton
    //                    color: "#e3e3e3"
    //                }

    //                PropertyChanges {
    //                    target: gradientStop1_exitButton
    //                    color: "#525252"
    //                }

    //                PropertyChanges {
    //                    target: collapseButton
    //                    checkable: false
    //                }
    //            },
    //            State {
    //                name: "presssedExitButtonState"
    //                when: exitButton.pressed
    //                PropertyChanges {
    //                    target: gradientStop_exitButton
    //                    color: "#e3e3e3"
    //                }

    //                PropertyChanges {
    //                    target: gradientStop1_exitButton
    //                    color: "#525252"
    //                }
    //            },
    //            State {
    //                name: "State2"
    //            }        ]
    //    }




}




