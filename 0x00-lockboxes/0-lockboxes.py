#!/usr/bin/python3


def canUnlockAll(boxes):
    """open all boxes"""
    lenght_boxes = len(boxes)

    def list_open_boxes(j, keys, lenght_boxes):
        keys.append(j)
        if len(keys) == lenght_boxes:
            return keys
        all_keys = keys
        for i in boxes[j]:
            if i not in keys and i < lenght_boxes:
                all_keys = list_open_boxes(i, keys, lenght_boxes)
        return all_keys

    if len(list_open_boxes(0, [], lenght_boxes)) == lenght_boxes:
        return True
    return False
