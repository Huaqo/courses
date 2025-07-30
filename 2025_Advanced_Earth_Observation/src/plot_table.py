import pandas as pd
import matplotlib.pyplot as plt


def plot_table(df, output_path, title, color, print_index=False):
    fig, ax = plt.subplots()

    fig.patch.set_facecolor(color)
    fig.tight_layout()
    ax.axis('off')
    ax.axis('tight')
    ax.set_facecolor(color)

    # Prepare cellText and colLabels depending on print_index
    if print_index:
        # Insert index as first column
        cell_text = pd.concat(
            [df.index.to_frame(index=False), df.reset_index(drop=True)], axis=1).values
        col_labels = [
            df.index.name if df.index.name else 'Index'] + list(df.columns)
    else:
        cell_text = df.values
        col_labels = df.columns

    table = ax.table(
        cellText=cell_text,
        colLabels=col_labels,
        cellLoc='center',
        loc='center'
    )
    ax.tick_params(colors="white")
    ax.set_title(title, color="white")

    for spine in ax.spines.values():
        spine.set_color("white")

    for key, cell in table.get_celld().items():
        cell.set_facecolor(color)  # use your passed color
        cell.get_text().set_color("white")  # make text white for contrast
        cell.set_edgecolor("white")

        if key[0] == 0:  # header row
            cell.get_text().set_weight('bold')

    table.scale(1, 2)

    plt.savefig(output_path, dpi=300, bbox_inches='tight')
    plt.close()
