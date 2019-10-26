#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../headers/add_cols.h"
#include "../headers/add_rows.h"
#include "../headers/comp_mat.h"
#include "../headers/copy_mat.h"
#include "../headers/del_to_sq.h"
#include "../headers/free_matrix.h"
#include "../headers/make_fill_matrix.h"
#include "../headers/print_mat.h"
#include "headers/AC_neg_data.h"
#include "headers/AC_pos_data.h"
#include "headers/AR_neg_data.h"
#include "headers/AR_pos_data.h"
#include "headers/CM_neg_data.h"
#include "headers/CM_pos_data.h"
#include "headers/DTS_neg_data.h"
#include "headers/DTS_pos_cols.h"
#include "headers/DTS_pos_rows.h"
#include "headers/DTS_pos_sqr.h"
#include "headers/FM_neg_data.h"
#include "headers/FM_pos_data.h"
#include "headers/GTZ_neg_data.h"
#include "headers/GTZ_pos_data.h"
#include "headers/PM_neg_data.h"
#include "headers/PM_pos_data.h"
#include "headers/COMP_neg_data.h"
#include "headers/COMP_pos_data.h"

#define SUCCESS 0
#define I_HATE_THIS_LIFE_GOD_WHY 1366613

int main(void)
{
    int positives = 0, negatives = 0;

    int check = ac_neg_data();
    if (!check)
        negatives++;
    else
        return check;

    check = ar_neg_data();
    if (!check)
        negatives++;
    else
        return check;

    check = cm_neg_data();
    if (!check)
        negatives++;
    else
        return check;

    check = dts_neg_data();
    if (!check)
        negatives++;
    else
        return check;

    check = fm_neg_data();
    if (!check)
        negatives++;
    else
        return check;

    check = gtz_neg_data();
    if (!check)
        negatives++;
    else
        return check;

    check = pm_neg_data();
    if (!check)
        negatives++;
    else
        return check;

    check = comp_neg_data();
    if (!check)
        negatives++;
    else
        return check;


    check = ar_pos_data();
    if (!check)
        positives++;
    else
        return check;

    check = ac_pos_data();
    if (!check)
        positives++;
    else
        return check;

    check = cm_pos_data();
    if (!check)
        positives++;
    else
        return check;

    check = dts_pos_cols();
    if (!check)
        positives++;
    else
        return check;

    check = dts_pos_rows();
    if (!check)
        positives++;
    else
        return check;

    check = dts_pos_sqr();
    if (!check)
        positives++;
    else
        return check;

    check = fm_pos_data();
    if (!check)
        positives++;
    else
        return check;

    check = gtz_pos_data();
    if (!check)
        positives++;
    else
        return check;

    check = pm_pos_data();
    if (!check)
        positives++;
    else
        return check;

    check = comp_pos_data();
    if (!check)
        positives++;
    else
        return check;

    if (positives == 10 && negatives == 8)
        return SUCCESS;
    else
        return I_HATE_THIS_LIFE_GOD_WHY;
}
