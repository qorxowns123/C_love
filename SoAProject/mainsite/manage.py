#!/usr/bin/env python
import os
import sys

if __name__ == "__main__":
    print('서버를 실행합니다')
    os.environ.setdefault("DJANGO_SETTINGS_MODULE", "mainsite.settings")
    try:
        from django.core.management import execute_from_command_line
    except ImportError as exc:
        raise ImportError(
            "Couldn't import Django. Are you sure it's installed and "
            "available on your PYTHONPATH environment variable? Did you "
            "forget to activate a virtual environment?"
        ) from exc
    execute_from_command_line(sys.argv)
