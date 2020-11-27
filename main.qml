import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import Qt.labs.qmlmodels 1.0

import Lib 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Properties table")

    TableView {
        anchors.fill: parent

        model: PropertiesModel {}

        delegate: DelegateChooser {
            role: "type"
            DelegateChoice {
                roleValue: PropertiesModel.String
                delegate: TextField {
                    text: model.value
                    selectByMouse: true
                }
            }
            DelegateChoice {
                roleValue: PropertiesModel.Integer
                delegate: SpinBox {
                    value: model.value
                }
            }
            DelegateChoice {
                roleValue: PropertiesModel.Boolean
                delegate: CheckBox {
                    checked: model.value
                }
            }
            DelegateChoice {
                delegate: Rectangle {
                    color: "beige"
                    implicitWidth: textLabel.width + 10
                    implicitHeight: textLabel.height
                    Text {
                        id: textLabel
                        anchors.centerIn: parent
                        text: model.name
                    }
                }
            }
        }
    }
}
