#!/usr/bin/python3


def canUnlockAll(boxes):
    """open all boxes"""
    lenght_boxes = len(boxes)
    if not lenght_boxes:
        return False

    def list_open_boxes(first_box_open, all_keys_gotten, lenght_boxes):
        all_keys_gotten.append(first_box_open)
        for key_box_gotten in all_keys_gotten:
            for key_in_box in boxes[key_box_gotten]:
                if (key_in_box not in all_keys_gotten and
                        key_in_box < lenght_boxes):
                    all_keys_gotten.append(key_in_box)
        return all_keys_gotten

    if len(list_open_boxes(0, [], lenght_boxes)) == lenght_boxes:
        return True
    return False
