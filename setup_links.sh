#!/bin/bash
mkdir ~/qmk_firmware/keyboards/bernd
ln -sfn ${PWD}/planck/keymaps/bernd/ ~/qmk_firmware/keyboards/planck/keymaps
ln -sfn ${PWD}/helidox/ ~/qmk_firmware/keyboards/bernd/
ln -sfn ${PWD}/kimiko/ ~/qmk_firmware/keyboards/bernd/
ln -sfn ${PWD}/ferris/ ~/qmk_firmware/keyboards/bernd/
ln -sfn ${PWD}/sweep/ ~/qmk_firmware/keyboards/bernd/
ln -sfn ${PWD}/skeletyl/ ~/qmk_firmware/keyboards/bernd/
ln -sfn ${PWD}/muellerbernd/ ~/qmk_firmware/users/
